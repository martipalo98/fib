#include <QLabel>

class MyLabel : public QLabel {
	Q_OBJECT

	public:
		MyLabel(QWidget *parent);
		bool checked = false;
		int totalrecaudation = 0;
		int totalcars = 0;
		int totalmotorcycles = 0;
		int totaltrucks = 0;

	public slots:
	    void ChangeHighwayColor(bool);
		void UpdateCarMotorcyclePrice();
		void UpdateTruckPrice();
		void UpdateCarNum();
		void UpdateMotorcycleNum();
		void UpdateTruckNum();
};
