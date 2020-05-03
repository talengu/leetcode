/******************************************************************************
 * File:             BST.h
 *
 * Author:             
 * Created:          08/14/19 
 * Description:      二分搜索树
 *****************************************************************************/
#include<iostream>
#include<cassert>
#include<string>
#include<vector>
#include<queue>
#include"FileOps.h"
#include"SequenceST.h"

using namespace std;
template<typename Key,typename Value>

class BST
{
	private:
		struct Node{
			Key key;
			Value value;
			Node *left;
			Node *right;

			Node(Key key, Value value){
				this->key=key;
				this->value=value;
				this->left=this->right=NULL;
			}
			Node(Node *node){
				this->key=node->key;
				this->value=node->value;
				this->left=node->left;
				this->right=node->right;
			}
		};
		Node *root;
		int count;


	public:
		BST(){
			root =NULL;
			count=0;
		};
		~BST(){
			destroy(root);
		};
		int size(){
			return count;
		}
		bool isEmpty(){
			return count==0;
		}
		void insert(Key key, Value value){
			// 若相同，在相当于更新这个key对于的value
			root=insert(root,key,value);

		}
	
		bool contain(Key key){
			return contain(root,key);
		}
	
		//search 的返回方式
		// 用户可以方便的修改值。
		Value* search(Key key){
			return search(root,key);
		}

		// 遍历方法 前中后遍历，深度优先遍历。
		void preOrder(){
			preOrder(root);
		}
		void inOrder(){
			inOrder(root);
		}
		void postOrder(){
			postOrder(root);
		}
		// 层序遍历,广度优先遍历 需要队列将每层的节点放入。
		void levelOrder(){
			queue<Node*> q;
			q.push(root);
			while(!q.empty()){
				Node *node=q.front();
				q.pop();
				cout<<node->key<<endl;
				if (node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
		}	
		Key minimun(){
			assert(count!=0);
			Node* minNode=minimun(root);
			return minNode->key;
		}
		Key maxmun(){
			assert(count!=0);
			Node* maxNode=maxmun(root);
			return maxNode->key;
		}
		void removeMin(){
			if(root)
				root=removeMin(root);
		}
		void removeMax(){
			if(root)
				root=removeMax(root);
		}

		// Hibbard's Hubbard Deletion logn //视频5-8
		void remove(Key key){
			root=remove(root,key);
		}
		// TODO: floor ceil
		
		// TODO: select rank
		// TODO: 支持重复的二分搜索树。
		// TODO: 平衡二叉树：如红黑树
		// TODO: 平衡二叉树和堆 treap 
		// trie 的实现，字典，比较一哈bst的性能差。
	private:
		// 以node为根进行插入操作。
		// 递归实现
		Node* insert(Node *node,Key key, Value value){

			if(node==NULL){
				count++;
				return new Node(key,value);
			}
			if (key==node->key)
				node->value=value;
			else if(key<=node->key)
				node->left=insert(node->left,key,value);
			else
				node->right=insert(node->right,key,value);
			return node;

		}
		bool contain(Node* node, Key key){
			if(node==NULL)
				return false;
			if(key==node->key)
				return true;
			else if(key<node->key)
				return contain(node->left,key);
			else
				return contain(node->right,key);
		}
		Value* search(Node* node,Key key){
			if(node==NULL)
				return NULL;
			if(key==node->key)
				return &(node->value);
			else if(key<node->key)
				return search(node->left,key);
			else
				return search(node->right,key);

		}
		void preOrder(Node* node){
			if (node!=NULL){
				cout<<node->key<<endl;
				preOrder(node->left);
				preOrder(node->right);
			}
		}
		void inOrder(Node* node){
			if (node!=NULL){
				inOrder(node->left);
				cout<<node->key<<endl;
				inOrder(node->right);
			}
		}
		void postOrder(Node* node){
			if (node!=NULL){
				inOrder(node->left);
				inOrder(node->right);
				cout<<node->key<<endl;
			}
		}
		void destroy(Node* node){
			if(node!=NULL){
				destroy(node->left);
				destroy(node->right);
				delete node;
				count--;
			}
		}
		Node* minimun(Node* node){
			if(node->left==NULL)
				return node;
			return minimun(node->left);
		}
		Node* maxmun(Node* node){
			if(node->right==NULL)
				return node;
			return maxmun(node->right);
		}
		Node* removeMin(Node* node){
			if(node->left==NULL){
				Node* rightNode=node->right;
				delete node;
				count--;
				return rightNode;
			}
			node->left=removeMin(node->left);
			return node;
		}
		Node* removeMax(Node* node){
			if(node->right==NULL){
				Node* leftNode=node->left;
				delete node;
				count --;
				return leftNode;
			}
			removeMax(node->right);
			return node;
		}
		Node* remove(Node* node,Key key){
			if(node==NULL)
				return NULL;
			if(key<node->key){
				node->left=remove(node->left,key);
				return node;
			}
			else if(key>node->key){
				node->right=remove(node->right,key);
				return node;
			}
			else{
				//key==node->key
				if(node->left==NULL){
					Node* rightNode=node->right;
					delete node;
					count--;
					return rightNode;
				}
				if(node->right==NULL){
					Node *leftNode=node->left;
					delete node;
					count--;
					return leftNode;
				}
				// left and right is not empty
				Node *successor=new Node(minimun(node->right));
				count++;
				successor->right=removeMin(node->right);
				successor->left=node->left;

				delete node;
				count--;

				return successor;
			}

		}


};


