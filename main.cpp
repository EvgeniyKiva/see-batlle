#include <iostream>




bool checking_coordinates (int x1,int y1,int x2,int y2, int deck){
    if ( x1<1 || x1>10 || y1<1 || y1>10 || x2<1 || x2>10 || y2<1||y2>10 || x1>x2 || y1>y2){
        return (true);
    }
    if ( (x1==x2 && y1==y2) || (x1!=x2 && y1!=y2) ){
        return (true);
    }
    if (x1==x2){
        if ((y2-y1)!=deck-1){
            return (true);
        }

    }
    if (y1==y2){
        if ((x2-x1)!=deck-1){
            return (true);
        }
    }
    return (false);
}
bool checking_location (bool player[10][10], int x1, int y1, int x2, int y2 ){
    if (x1==x2){
        for (int i=y1; i<=y2; i++){
            if (player[x1-1][i]== true){
                return (true);
            }
        }
    }
    if (y1==y2){
        for (int i=x1; i<=x2; i++){
            if (player[i][x1-1]== true){
                return (true);
            }
        }
    }
    return (false);
}


int main() {
    bool player1[10][10];
    bool player2[10][10];
    //int x,y;

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            player1[i][j]= false;
            player2[i][j]= false;
        }
    }

    std::cout << "Turn of player number 1";
    std::cin.get();


    for (int i=1; i<=4; i++ ){
        std::cout << "Player 1 enter the coordinates of the Single - 1x deck ship number " << i << " (x y)- ";
        int x,y;
        std::cin >> x;
        std::cin >> y;
        while ((x<1||x>10)||(y<1||y>10)||player1[x-1][y-1]== true){
            std::cout << "The coordinates are not correct, try again." <<std::endl;
            std::cin >> x;
            std::cin >> y;
        }

        player1[x-1][y-1] = true;

    }
    for (int i = 3; i>=0; i--)
        for (int j = 1; j <= i; j++) {

            std::cout << "Player 1 Enter the start and end coordinates of the " << 5 - i << "x deck ship number " << j
                      << " (x1 y1 x2 y2) - ";
            int x1, y1, x2, y2;
            std::cin >> x1;
            std::cin >> y1;
            std::cin >> x2;
            std::cin >> y2;
            while ((checking_coordinates(x1, y1, x2, y2, 5-i)) || (checking_location(player1, x1, y1, x2, y2))) {
                std::cout << "The coordinates are not correct, try again." << std::endl;
                std::cin >> x1;
                std::cin >> y1;
                std::cin >> x2;
                std::cin >> y2;
            }
            if (x1 == x2) {
                for (int i = y1; i <= y2; i++) {
                    player1[x1 - 1][i-1] = true;
                }
            } else if (y1 == y2) {
                for (int i = x1; i <= x2; i++) {
                    player1[i-1][y1 - 1] = true;
                }
            }


        };
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            std:: cout << player1[i][j] << " ";
        }
        std::cout<< std:: endl;
    }


    //system("cls");
    std::cout << "Turn of player number 2" << std::endl;
    std::cin.get();


    for (int i=1; i<=4; i++ ){
        std::cout << "Player 2 enter the coordinates of the Single - 1x deck ship number " << i << " (x y)- ";
        int x,y;
        std::cin >> x;
        std::cin >> y;
        while ((x<1||x>10)||(y<1||y>10)||player2[x-1][y-1]== true){
            std::cout << "The coordinates are not correct, try again." <<std::endl;
            std::cin >> x;
            std::cin >> y;
        }

        player2[x-1][y-1] = true;

    }
    for (int i = 3; i>=0; i--)
        for (int j = 1; j <= i; j++) {

            std::cout << "Player 2 Enter the start and end coordinates of the " << 5 - i << "x deck ship number " << j
                      << " (x1 y1 x2 y2) - ";
            int x1, y1, x2, y2;
            std::cin >> x1;
            std::cin >> y1;
            std::cin >> x2;
            std::cin >> y2;
            while ((checking_coordinates(x1, y1, x2, y2, 5-i)) || (checking_location(player2, x1, y1, x2, y2))) {
                std::cout << "The coordinates are not correct, try again." << std::endl;
                std::cin >> x1;
                std::cin >> y1;
                std::cin >> x2;
                std::cin >> y2;
            }
            if (x1 == x2) {
                for (int i = y1; i <= y2; i++) {
                    player2[x1 - 1][i-1] = true;
                }
            } else if (y1 == y2) {
                for (int i = x1; i <= x2; i++) {
                    player2[i-1][y1 - 1] = true;
                }
            }


        };
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            std:: cout << player2[i][j] << " ";
        }
        std::cout<< std:: endl;
    }


    int shot_x, shot_y;
    bool hit_player1= true;
    bool hit_player2= true;
    bool game= true;
    int deck1=20;
    int deck2=20;
    //std::cin>> shot_x, shot_y;
    while (game){
        while (hit_player1){
            std::cout << "Round Player 1" << std::endl << "Enter the coordinates of the shot - ";
            std::cin >> shot_x >> shot_y;
            while (shot_x>10 || shot_x<1 || shot_y >10 || shot_y <0){
                std::cout << "The coordinates are not correct, try again." <<std::endl;
                std::cin >> shot_x;
                std::cin >> shot_y;
            }
            if (player2[shot_x-1][shot_y-1]== true) {
                std::cout << "Hitting the target" << std::endl;
                //hit = true;
                deck2--;
                player2[shot_x-1][shot_y-1]= false;
                if (deck2 == 0) {
                    std::cout << "Player 1 won!"<<std::endl;
                    game= false;
                    hit_player1= false;
                    hit_player2= false;
                }
            }
            else {
                std::cout << "Missed" << std::endl;
                hit_player1= false;
                hit_player2= true;
            }

        }
        while (hit_player2){
            std::cout << "Round Player 2" << std::endl << "Enter the coordinates of the shot - ";
            std::cin >> shot_x >> shot_y;
            while (shot_x>10 || shot_x<1 || shot_y >10 || shot_y <0){
                std::cout << "The coordinates are not correct, try again." <<std::endl;
                std::cin >> shot_x;
                std::cin >> shot_y;
            }
            if (player1[shot_x-1][shot_y-1]== true) {
                std::cout << "Hitting the target" << std::endl;
                //hit = true;
                deck1--;
                player1[shot_x-1][shot_y-1]= false;
                if (deck1 == 0) {
                    std::cout << "Player 2 won!"<<std::endl;
                    game= false;
                    hit_player1= false;
                    hit_player2= false;
                }
            }
            else {
                std::cout << "Missed" << std::endl;
                hit_player2= false;
                hit_player1= true;
            }

        }
    }








    return 0;
}
