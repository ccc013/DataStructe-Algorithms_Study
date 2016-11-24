#ifndef CSTACK_H_
#define CSTACK_H_
#include<queue>
using std::queue;

template <typename T>
class CStack{
public:
	CStack(){}
	~CStack(){}

	void append(const T& data);
	T remove();
	bool empty(){
		return q1.empty() && q2.empty();
	}
private:
	queue<T> q1;
	queue<T> q2;
};

template<typename T>
void CStack<T>::append(const T& data){
	// 插入首选非空的队列，当两个队列都空的时候，默认插入队列1
	if (q1.empty()){
		q2.push(data);
	}
	else{
		q1.push(data);
	}
}

template<typename T>
T CStack<T>::remove(){
	// 删除元素的时候，将非空的队列的所有元素，除了队尾元素外，都插入到空的队列中
	T res;
	if (q1.empty()){
		while (q2.size() > 1){
			T& data = q2.front();
			q2.pop();
			q1.push(data);
		}
		res = q2.front();
		q2.pop();
	}
	else{
		while (q1.size() > 1){
			T& data = q1.front();
			q1.pop();
			q2.push(data);
		}
		res = q1.front();
		q1.pop();
	}
	return res;
}

#endif