#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Ikkai27


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */

//bool M[25][25] = {{false}};
using VB=vector<bool>;
using VVB = vector<VB>;
VVB M;
VVB Reina;
VVB Soldats_enemics;
VVB Reines_enemigues;
int IR[8] = { 1, 1, 0, -1, -1, -1,  0,  1 };
int JR[8] = { 0, 1, 1,  1,  0, -1, -1, -1 };
int I[4] = { 1, 0, -1, 0};
int J[4] = { 0, 1, 0, -1};
int caminar_treballadores(Pos a, int aux){
  vector<vector<bool>> visitat(25,vector<bool>(25,false));
  priority_queue<pair<int,pair<Pos,Dir>>,vector<pair<int,pair<Pos,Dir>>>, greater<pair<int,pair<Pos,Dir>>>>pesols;
  pesols.push({0,{{a.i,a.j},Up}});
  visitat[a.i][a.j]=true;
  bool qwerty=true;
  while(not pesols.empty()){
      auto ara = pesols.top();
      pesols.pop();
      for(int i=0;i<4;++i){
        int pesol_actual=ara.first;
        int x_act=ara.second.first.i+I[i];
        int y_act=ara.second.first.j+J[i];
        if(pos_ok(x_act,y_act) and not visitat[x_act][y_act]) {
            visitat[x_act][y_act]=true;
            if(qwerty) {
              if(i==0)ara.second.second = Down;
              if(i==1)ara.second.second = Right;
              if(i==2)ara.second.second = Up;
              if(i==3)ara.second.second = Left;
            }
            if ((not Soldats_enemics[x_act][y_act] and not Reines_enemigues[x_act][y_act] and aux == 0 and (cell(x_act,y_act).type != Water and cell(x_act,y_act).id == -1 and not M[x_act][y_act] and not Reina[x_act][y_act]) or (aux == 1 and cell(x_act,y_act).type != Water and cell(x_act,y_act).id == -1 and not M[x_act][y_act] and not Reines_enemigues[x_act][y_act])) or
                (not Soldats_enemics[x_act][y_act] and not Reines_enemigues[x_act][y_act] and aux==2 and not M[x_act][y_act] and cell(x_act,y_act).type != Water and not Reina[x_act][y_act] and ant(cell(x_act,y_act).id).player != me())){
            //if(cell(x_act,y_act).type != Water and cell(x_act,y_act).id == -1 and not M[x_act][y_act] and not Reina[x_act][y_act]){
              if(cell(x_act,y_act).bonus != None and cell(x_act,y_act).type != Water and aux != 2 and not Reines_enemigues[x_act][y_act]){
                if (ara.second.second == Up){
                  M[a.i-1][a.j] = true;
                  return 1;
                }else if (ara.second.second == Down){
                  M[a.i+1][a.j] = true;
                  return 2;
                }else if (ara.second.second == Right){
                  M[a.i][a.j+1] = true;
                  return 3;
                }else if (ara.second.second == Left){
                  M[a.i][a.j-1] = true;
                  return 4;
                }
              }
              if(aux == 2 and cell(x_act,y_act).id != -1 and ant(cell(x_act,y_act).id).type != Queen){
                if(ant(cell(x_act,y_act).id).type == Worker) {
                  if (ara.second.second == Up){
                    M[a.i-1][a.j] = true;
                    Soldats_enemics[a.i-1][a.j] = true;
                    return 1;
                  }else if (ara.second.second == Down){
                    M[a.i+1][a.j] = true;
                    Soldats_enemics[a.i+1][a.j] = true;
                    return 2;
                  }else if (ara.second.second == Right){
                    M[a.i][a.j+1] = true;
                    Soldats_enemics[a.i][a.j+1] = true;
                    return 3;
                  }else if (ara.second.second == Left){
                    Soldats_enemics[a.i][a.j-1] = true;
                    M[a.i][a.j-1] = true;
                    return 4;
                  }
                }else if(ant(cell(x_act,y_act).id).type == Soldier) {
                  if (ara.second.second == Up){
                    M[a.i-1][a.j] = true;
                    return 1;
                  }else if (ara.second.second == Down){
                    M[a.i+1][a.j] = true;
                    return 2;
                  }else if (ara.second.second == Right){
                    M[a.i][a.j+1] = true;
                    return 3;
                  }else if (ara.second.second == Left){
                    M[a.i][a.j-1] = true;
                    return 4;
                  }
                }
              }
              pesols.push({pesol_actual+1,{{x_act,y_act},ara.second.second}});
            }else if (aux == 0 and (cell(x_act,y_act).type != Water and not Reina[x_act][y_act])
                 and (cell(a.i+1,a.j).id != -1 and ant(cell(a.i+1,a.j).id).player !=me()
                   or cell(a.i-1,a.j).id != -1 and ant(cell(a.i-1,a.j).id).player !=me()
                   or cell(a.i,a.j+1).id != -1 and ant(cell(a.i,a.j+1).id).player !=me()
                   or cell(a.i,a.j-1).id != -1 and ant(cell(a.i,a.j-1).id).player !=me())) {
              if (ara.second.second == Up){
                  return 2;
                }else if (ara.second.second == Down){
                  return 1;
                }else if (ara.second.second == Right){
                  return 4;
                }else if (ara.second.second == Left){
                  return 3;
                }
            }
        }
      }
      qwerty=false;

  }
  return 0;
}

int tornar_a_reina(Pos a){
  vector<vector<bool>> visitat(25,vector<bool>(25,false));
  priority_queue<pair<int,pair<Pos,Dir>>,vector<pair<int,pair<Pos,Dir>>>, greater<pair<int,pair<Pos,Dir>>>>pesols;
  pesols.push({0,{{a.i,a.j},Up}});
  visitat[a.i][a.j]=true;
  bool qwerty=true;
  while(not pesols.empty()){
      auto ara = pesols.top();
      pesols.pop();
      for(int i=0;i<4;++i){
        int pesol_actual=ara.first;
        int x_act=ara.second.first.i+I[i];
        int y_act=ara.second.first.j+J[i];
        if(pos_ok(x_act,y_act) and not visitat[x_act][y_act]) {
            visitat[x_act][y_act]=true;
            if(qwerty) {
              if(i==0)ara.second.second = Down;
              if(i==1)ara.second.second = Right;
              if(i==2)ara.second.second = Up;
              if(i==3)ara.second.second = Left;
            }
            if(not Soldats_enemics[x_act][y_act] and cell(x_act,y_act).type != Water and cell(x_act,y_act).id == -1 and not M[x_act][y_act] and cell(x_act, y_act).bonus == None){
              if(Reina[x_act][y_act]){
                if (ara.second.second == Up){
                  M[a.i-1][a.j] = true;
                  return 1;
                }else if (ara.second.second == Down){
                  M[a.i+1][a.j] = true;
                  return 2;
                }else if (ara.second.second == Right){
                  M[a.i][a.j+1] = true;
                  return 3;
                }else if (ara.second.second == Left){
                  M[a.i][a.j-1] = true;
                  return 4;
                }
              }
              pesols.push({pesol_actual+1,{{x_act,y_act},ara.second.second}});
            }
        }
      }
      qwerty=false;

  }
  return 0;
}

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    vector<int> reines = queens(me());
    vector<int> soldats = soldiers(me());
    vector<int> treballadors = workers(me());
    Reina = VVB(25,VB(25,false));
    Soldats_enemics = VVB(25,VB(25,false));
    Reines_enemigues = VVB(25,VB(25,false));
    int numreina = 0;
    int fReinaid = reines[numreina];
    Ant fReina = ant(fReinaid);
    while(fReina.life < 1) {
      fReinaid = reines[++numreina];
      fReina = ant(fReinaid);
    }
    int i;
    for(int k = 0; k<4; ++k) {
      if(me()!=k){
        vector<int> enemy_soldiers = soldiers(k);
        for(int j = 0; j<enemy_soldiers.size(); ++j) {
          for (i = 0; i<4; ++i) {
            int x_act = ant(enemy_soldiers[j]).pos.i+I[i];
            int y_act = ant(enemy_soldiers[j]).pos.j+J[i];
            if (pos_ok(x_act, y_act)) {
              Soldats_enemics[x_act][y_act] = true;
            }
          }
        }
        vector<int> enemy_queens = queens(k);
        for(int j = 0; j<enemy_queens.size(); ++j) {
          for (i = 0; i<4; ++i) {
            int x_act = ant(enemy_queens[j]).pos.i+I[i];
            int y_act = ant(enemy_queens[j]).pos.j+J[i];
            if (pos_ok(x_act, y_act)) {
              Reines_enemigues[x_act][y_act] = true;
            }
          }
        }
      }
    }
    bool quieta = false;
    if(not reines.empty()) {
      for (i = 0; i<8; ++i) {
        int x_act = ant(reines[numreina]).pos.i+IR[i];
        int y_act = ant(reines[numreina]).pos.j+JR[i];
        if (pos_ok(x_act, y_act)) {
          Reina[x_act][y_act] = true;
        }
      }
    }
    
    M = VVB(25,VB(25,false));
    for (i = 0; i<25; ++i) {
      for (int j = 0; j<25; ++j) M[i][j] = false;
    }
  //WORKERS
    for(i = 0; i < treballadors.size(); ++i) {
      if(ant(treballadors[i]).life < 1 and ant(treballadors[i]).bonus != None){
        leave(treballadors[i]);
      }
      int aux = 0;
      Pos p = ant(treballadors[i]).pos;
      if (ant(treballadors[i]).bonus == Bread or ant(treballadors[i]).bonus == Leaf or ant(treballadors[i]).bonus == Seed){
        if (Reina[p.i][p.j]){
          leave(treballadors[i]);
          quieta = true;
          aux = caminar_treballadores(p,0);
        }else aux = tornar_a_reina(p);
      }else aux = caminar_treballadores(p,0);
      if(cell(p).bonus != None and not Reina[p.i][p.j] and ant(treballadors[i]).life >= 5) take(treballadors[i]);
      if (aux == 1){
        move(treballadors[i], Up);
      }else if (aux == 2){
        move(treballadors[i], Down);
      }else if (aux == 3){
        move(treballadors[i], Right);
      }else if (aux == 4){
        move(treballadors[i], Left);
      }
    }
    //SOLDATS
    for(i = 0; i < soldats.size(); ++i) {
      int aux = caminar_treballadores(ant(soldats[i]).pos,2);
      if (aux == 1){
          move(soldats[i], Up);
        }else if (aux == 2){
          move(soldats[i], Down);
        }else if (aux == 3){
          move(soldats[i], Right);
        }else if (aux == 4){
          move(soldats[i], Left);
        }
    }
    //REINA
    if(not reines.empty()){
      for (i = 0; i<4; ++i) {
        int x_act = fReina.pos.i+I[i];
        int y_act = fReina.pos.j+J[i];
        if (pos_ok(x_act, y_act)) {
          if(cell(x_act, y_act).type != Water and cell(x_act, y_act).id != -1){
            if (ant(cell(x_act, y_act).id).bonus != None) quieta = true;
          }
        }
      }
      int bonus1 = ant(fReinaid).reserve[0];
      int bonus2 = ant(fReinaid).reserve[1];
      int bonus3 = ant(fReinaid).reserve[2];
      bool ous = false;
      if(bonus1>0 and bonus2>0 and bonus3>0) ous = true;
      if (!quieta and !ous or (bonus1<1 or bonus2<1 or bonus3<1) or
          ((cell(fReina.pos+Left).bonus != None or cell(fReina.pos+Left).type == Water)
            and (cell(fReina.pos+Right).bonus != None or cell(fReina.pos+Right).type == Water)
            and (cell(fReina.pos+Up).bonus != None or cell(fReina.pos+Up).type == Water)
            and (cell(fReina.pos+Down).bonus != None or cell(fReina.pos+Down).type == Water) and !ous)){
        int aux = caminar_treballadores(fReina.pos,1);
        if (aux == 1){
            move(fReinaid, Up);
          }else if (aux == 2){
            move(fReinaid, Down);
          }else if (aux == 3){
            move(fReinaid, Right);
          }else if (aux == 4){
             move(fReinaid, Left);
          }
        if(cell(fReina.pos).bonus != None) take(fReinaid);
      }

      if(soldats.size()>=2 or ous){
        if (cell(fReina.pos.i, fReina.pos.j+1).id == -1 and cell(fReina.pos.i, fReina.pos.j+1).type != Water) {
          lay(fReinaid, Right, Worker);          
        }else if (cell(fReina.pos.i, fReina.pos.j-1).id == -1 and cell(fReina.pos.i, fReina.pos.j-1).type != Water) {
          lay(fReinaid, Left, Worker);          
        }else if (cell(fReina.pos.i-1, fReina.pos.j).id == -1 and cell(fReina.pos.i-1, fReina.pos.j).type != Water) {
          lay(fReinaid, Up, Worker);          
        }else if (cell(fReina.pos.i+1, fReina.pos.j).id == -1 and cell(fReina.pos.i+1, fReina.pos.j).type != Water) {
          lay(fReinaid, Down, Worker);          
        }
      }else if(bonus1>2 and bonus2>2 and bonus3>2) {
        if (cell(fReina.pos.i, fReina.pos.j+1).id == -1 and cell(fReina.pos.i, fReina.pos.j+1).type != Water) {
          lay(fReinaid, Right, Soldier);          
        }else if (cell(fReina.pos.i, fReina.pos.j-1).id == -1 and cell(fReina.pos.i, fReina.pos.j-1).type != Water) {
          lay(fReinaid, Left, Soldier);          
        }else if (cell(fReina.pos.i-1, fReina.pos.j).id == -1 and cell(fReina.pos.i-1, fReina.pos.j).type != Water) {
          lay(fReinaid, Up, Soldier);          
        }else if (cell(fReina.pos.i+1, fReina.pos.j).id == -1 and cell(fReina.pos.i+1, fReina.pos.j).type != Water) {
          lay(fReinaid, Down, Soldier);          
        }
      }
      
      
    }
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
