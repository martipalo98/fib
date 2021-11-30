#include "MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent=0):QLineEdit(parent) {
}

void MyLineEdit::checkLetter(QString s) {
    bool matches = false;
    QString guess = s.toUpper();
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == guess[0]) {
            visibleword[i] = guess[0];
            matches = true;
        }
    }

    if (!matches and guess != "") {
        //if (!used_chars.contains(guess)) {
            //used_chars.append(guess);
            --allowederrors;
            emit updateErrorCount(allowederrors);

            if (allowederrors == 0) {
                setStyleSheet("background-color: rgba(255,0,0);");
                clear();
                setEnabled(0);
            }
        //}
    } else {
        emit updateVisibleWord(visibleword);
        if (word == visibleword) {
            setStyleSheet("background-color: rgba(0,255,0);");
            setEnabled(0);
            clear();
        }
    }
}

void MyLineEdit::resetGame() {
    allowederrors = 5;
    emit updateErrorCount(allowederrors);

    visibleword = "**********";
    emit updateVisibleWord(visibleword);
    
    setStyleSheet("");
    setEnabled(1);
    clear();
}
