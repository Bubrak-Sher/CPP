// I am deferent, I am Scorpio!
# include <iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* next;
};

void disp_1(Node *s){
	while(s != NULL){
		cout << s->value << " "; 
		s = s->next;
	}
}

main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();
	
	head->value = 6;
	head->next = second;
	
	second->next = third;
	second->value = 7;
	
	third->next = fourth;
	third->value = 8;
	
	fourth->value = 9;
	fourth->next = NULL;
	
	disp_1(head);
	
}
