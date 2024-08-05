#include<iostream>
using namespace std;

	char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	char turn ='x';
	int colum,row;
	bool draw=false;
void display_board(){
	system("cls");
	cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
	cout<<"\t\t     |     |     \n";
}
void player_turn(){
	int choice;
	
	if(turn=='x')
		cout<<"\n\tplayer1 [x] turn :";
		
	if(turn=='o')
		cout<<"\n\tplayer2 [o] turn :";
	cin>>choice;
	switch(choice){
		
			case 1: row =0; colum=0;break;
			case 2: row =0; colum=1;break;
			case 3: row =0; colum=2;break;
			case 4: row =1; colum=0;break;
			case 5: row =1; colum=1;break;	
			case 6: row =1; colum=2;break;
			case 7: row =2; colum=0;break;
			case 8: row =2; colum=1;break;
			case 9: row =2; colum=2;break;
			
			default:
			    cout<<endl<<"Invaild optoin \n";
			    break;
				}
				
				if(turn=='x'&&board[row][colum]!='x'&&board[row][colum]!='o')
				{
					board[row][colum]='x';
					turn ='o';
				}
				else if(turn=='o'&&board[row][colum]!='x'&&board[row][colum]!='o')
				{
					board[row][colum]='o';
					turn ='x';
				}
				else
				{
					cout<<"box alrady filled!\n please try again!!\n\n";
					player_turn();
				}
}
 bool gamevoer(){
 	for(int i=0;i<3;i++)
 	if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]||board[0][i]==board[1][i]&&board[0][i]==board[2][i])
 	return false;
 	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]||board[0][2]==board[1][1]&&board[0][0]==board[2][0])
 	return false;
 	for(int i=0;i<3;i++)
 	for(int j=0;j<3;j++)
 	if(board[i][j]!='x'&&board[i][j]!='o')
 	return true;
 	
 	draw=true;
 	return false;
 }
main(){
	int choice;

	cout<<"\n      T i c k C r o s s G a m e"<<endl;
	cout<<"\n\tPlayer1[o]\n\tPlayer2[x]\n";
	while(gamevoer())
	{
	display_board();
	player_turn();
	gamevoer();
	
	}
	if(turn=='x'&&draw == false)
	cout<<endl<<"player2 [o] wins!!";
	else if(turn=='o'&&draw == false)
	cout<<endl<<"player1 [x] wins!!";
 	else
 	cout<<endl<<"game draw!\n";
}
