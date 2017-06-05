//#include <windows.h>

#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <time.h>

using namespace std;

class Member {
	public:
		//unsigned
		int _member_public_key;
		//unsigned
		int _member_very_secret_key;
					 
		Member * _left_hand = NULL,
			   * _right_hand = NULL;
		
		int getID() const {
			return this->_member_public_key;
		}
		
		int getInfo() const {
			return this->_member_very_secret_key;
		}
		
		void set(int pub, int sec){
			this->_member_public_key = pub;
			this->_member_very_secret_key = sec;
			cout << "Member #" << getID() << " received info " << getInfo() << "\n";
		}
		
		Member(int pub, int sec){
			this->_member_public_key = pub;
			this->_member_very_secret_key = sec;
			cout << "Member #" << getID() << " received info " << getInfo() << "\n";
		}
		
		Member(){
			//
		}
		
		~Member(){
			//
		}
		
		int killChildren(){
			int count = 0;
			if(_left_hand) {
				count++;
				count += _left_hand->killChildren();
			}
			if(_right_hand){
				count++;
				count += _right_hand->killChildren();
			}
			_left_hand = NULL;
			delete _left_hand;
			_right_hand = NULL;
			delete _right_hand;
			return count;
		}
		
		void setInfo(int key){
			this->_member_very_secret_key = key;
		}
		
		Member(const Member & other){
			if(other._left_hand){
				_left_hand = new Member(*(other._left_hand));
			}
			if(other._right_hand){
				_right_hand = new Member(*(other._right_hand));
			}
			_member_public_key = other._member_public_key;
			_member_very_secret_key = other._member_very_secret_key;
		}
		
		Member operator = (Member &other) {
			if(other._left_hand){
				_left_hand = new Member();
				*_left_hand = *(other._left_hand);
			}
			if(other._right_hand){
				_right_hand = new Member();
				*_right_hand = *(other._right_hand);
			}
			this->_member_public_key = other.getID();
			this->_member_very_secret_key = other.getInfo();
			return *this;
		}
};

class Piramida {
	private:
		int count = 0;
		Member * _root = NULL;
		
	public:
		int getCount() const {
			return count;
		}
		
		friend istream & operator >> (istream & is, Piramida * Vladikavkaz);
		friend ostream & operator << (ostream & os, const Piramida * Vladikavkaz);
		
		Piramida(){
			//
		}
		
		Piramida(int publ, int secr){
			_root = new Member();
			_root->set(publ, secr);
		}
		
		~Piramida(){
			//
		}
		
		void addMember(int publ, int secr){
			if(count == 6){
				cout << "Oh, my apologies, head afraid that very big groups are interesting for police.\nPlease, use other other company\n";
				return;
			}
			addMemberPart(&_root, publ, secr);
		}
		
		void addMemberPart(Member ** parent, int publ, int secr){
			if((*parent) == NULL){
				(*parent) = new Member(publ, secr);
				count++;
			} else
			if(publ > (*parent)->getID()){
				addMemberPart(&(*parent)->_right_hand, publ, secr);
			} else
			if(publ < (*parent)->getID()){
				addMemberPart(&(*parent)->_left_hand, publ, secr);
			}
		}
		
		void printSecretSchema() const {
			int n = 16;
			int iter = 1;
			for(int i = 0; i < 3; i++){
				for(int k=0; k<iter; k++){
					for(int j = 1; j <= n/iter; j++)
						cout << "  ";
					cout << "  " << this->getID(i, k);
					for(int j = 1; j <= n/iter; j++)
						cout << "  ";
				}
				cout << "\n";
				for(int k=0; k<iter; k++){
					for(int j = 1; j <= n/iter; j++)
						cout << "  ";
					cout << this->getInfo(i, k);
					for(int j = 1; j <= n/iter; j++)
						cout << "  ";
				}
				cout << "\n\n";
				iter = iter*2;
			}
		}
		
		const int getID(int line, int position) const {
			if(_root){
				if(line == 0) return _root->getID();
				if(line == 1) {
					if(position == 0) if (_root->_left_hand) return _root->_left_hand->getID(); else return 0;
					if(position == 1) if (_root->_right_hand) return _root->_right_hand->getID(); else return 0;
				}
				if(line == 2) {
					if(position == 0){
						if(_root->_left_hand) if (_root->_left_hand->_left_hand) return _root->_left_hand->_left_hand->getID();
						return 0;
					}
					if(position == 1){
						if(_root->_left_hand) if (_root->_left_hand->_right_hand) return _root->_left_hand->_right_hand->getID();
						return 0;
					}
					if(position == 2){
						if(_root->_right_hand) if (_root->_right_hand->_left_hand) return _root->_right_hand->_left_hand->getID();
						return 0;
					}
					if(position == 3){
						if(_root->_right_hand != NULL) if (_root->_right_hand->_right_hand) return _root->_right_hand->_right_hand->getID();
						return 0;
					}
				}
			}
			return 0;
		}
		
		int getInfo(int line, int position) const {
			if(_root){
				if(line == 0) return _root->getInfo();
				if(line == 1) {
					if(position == 0) if (_root->_left_hand) return _root->_left_hand->getInfo(); else return 0;
					if(position == 1) if (_root->_right_hand) return _root->_right_hand->getInfo(); else return 0;
				}
				if(line == 2) {
					if(position == 0){
						if(_root->_left_hand) if (_root->_left_hand->_left_hand) return _root->_left_hand->_left_hand->getInfo();
						return 0;
					}
					if(position == 1){
						if(_root->_left_hand) if (_root->_left_hand->_right_hand) return _root->_left_hand->_right_hand->getInfo();
						return 0;
					}
					if(position == 2){
						if(_root->_right_hand) if (_root->_right_hand->_left_hand) return _root->_right_hand->_left_hand->getInfo();
						return 0;
					}
					if(position == 3){
						if(_root->_right_hand) if (_root->_right_hand->_right_hand) return _root->_right_hand->_right_hand->getInfo();
						return 0;
					}
				}
			}
			return 0;
		}
		
		Member * getMemberByIndex(int index){
			Member * mem = findMember(_root, index);
			cout << "Member #" << mem->getID() << " has info " << mem->getInfo() << " was detected.\n";
			return mem;
		}
		
		Member * findMember(Member * parent, int index){
			if(parent->getID() == index) return parent;
			if(parent->getID() > index) return findMember(parent->_left_hand, index);
			if(parent->getID() < index) return findMember(parent->_right_hand, index);
		}
		
		void deleteFrom(int index){
			Member * mem = getMemberByIndex(index);
			int killed = mem->killChildren();
			memset(mem, 0 , sizeof(Member));
			count -= killed;
		}
		
		void changingInfoForConfidentialityPurposes(){
			touchAll(_root);
		}
		
		void touchAll(Member * from){
			if(from->_left_hand != NULL) touchAll(from->_left_hand);
			if(from->_right_hand != NULL) touchAll(from->_right_hand);
			from->setInfo(rand() % 9000 + 1000);
		}
		
		Piramida operator = (const Piramida other) {
			_root = new Member();
			*_root = *(other._root);
			count = other.count;
			return *this;
		}
};

istream & operator >> (istream & is, Piramida * Vladikavkaz) {
	int index, info;
	is >> index >> info;
	Vladikavkaz->addMember(index, info);
	return is;
}

ostream & operator << (ostream & os, const Piramida * Vladikavkaz) {
	int n = 16;
	int iter = 1;
	for(int i = 0; i < 3; i++){
		for(int k=0; k<iter; k++){
			for(int j = 1; j <= n/iter; j++)
				os << "  ";
			os << "  " << Vladikavkaz->getID(i, k);
			for(int j = 1; j <= n/iter; j++)
				os << "  ";
		}
		os << "\n";
		for(int k=0; k<iter; k++){
			for(int j = 1; j <= n/iter; j++)
				os << "  ";
			os << Vladikavkaz->getInfo(i, k);
			for(int j = 1; j <= n/iter; j++)
				os << "  ";
		}
		os << "\n\n";
		iter = iter*2;
	}
	return os;
}

int main(){
	srand(time(NULL));
	
	Piramida * MMM = new Piramida(8, 33333);
	MMM->addMember(10, 5555);
	cin >> MMM;
	/*MMM->addMember(5, 1333);
	MMM->addMember(3, 2222);
	MMM->addMember(6, 2626);
	MMM->addMember(8, 1111);
	MMM->addMember(9, 1212);
	MMM->addMember(7, 2525);*/
	/*
	Piramida * DigitalMolecularMatter = new Piramida();
	*DigitalMolecularMatter = *MMM;
	
	MMM->changingInfoForConfidentialityPurposes();
	DigitalMolecularMatter->deleteFrom(5);
	
	DigitalMolecularMatter->printSecretSchema();
	MMM->printSecretSchema();
	cout << "========================\n";*/
	cout << MMM;
	return 0;
}
