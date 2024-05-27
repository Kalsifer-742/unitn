#include <iostream>
using namespace std;

void annd(int val1, int val2){
	cout<<"|"<<val1<<"|"<<val2<<"|"<<(val1&&val2)<<"|"<<endl;
}
void ooor(int val1, int val2){
	cout<<"|"<<val1<<"|"<<val2<<"|"<<(val1||val2)<<"|"<<endl;
}
void xoor(int val1, int val2){
	cout<<"|"<<val1<<"|"<<val2<<"|"<<(val1^val2)<<"|"<<endl;
}
int main(){
	cout<<"tabella di verità dell'operatore AND &&"<<endl;
	cout<<"|A|B|O|"<<endl;
	annd(0,0);
	annd(1,0);
	annd(0,1);
	annd(1,1);

	cout<<"tabella di verità dell'operatore OR ||"<<endl;
	cout<<"|A|B|O|"<<endl;
	ooor(0,0);
	ooor(1,0);
	ooor(0,1);
	ooor(1,1);

	cout<<"tabella di verità dell'operatore XOR ^"<<endl;
	cout<<"|A|B|O|"<<endl;
	xoor(0,0);
	xoor(1,0);
	xoor(0,1);
	xoor(1,1);

}
