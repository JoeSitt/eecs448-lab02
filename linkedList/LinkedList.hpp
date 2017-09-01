/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO
		Fix this method
		Fixed-Joe
	*/
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	//Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO
		Fix this method
	*/
	Node<T>* searcher = nullptr;
	if(isEmpty()){
		return(false);
	}
	for(searcher = m_front; searcher != nullptr; searcher = searcher-> getNext()){
		if(searcher -> getValue() == value){
			return(true);
		}

	}
	for(searcher = m_front; searcher != nullptr; searcher = searcher-> getNext()){
		if(searcher -> getValue() != value){
			return(false);
		}

	}

	return(true);
	//return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	//Node<T>* lastNode = nullptr;
	//Node<T>* secondintoLast = nullptr;
	//bool isRemoved = false;

	/** TODO
		Fix this method
	*/
	if(isEmpty()){
		return(false);
	}
	else if(size() == 1){
		Node<T>* back = nullptr;
		back = m_front;
		removeFront();
		m_size--;
		return(true);
	}
	else{
		Node<T>* traverseEnd = nullptr;
		traverseEnd = m_front;
		while(traverseEnd -> getNext() != nullptr){
			traverseEnd = traverseEnd -> getNext();
		}
		Node<T>* almostEnd = nullptr;
		almostEnd = m_front;
		while(almostEnd -> getNext() != traverseEnd){
			almostEnd = almostEnd -> getNext();
		}
		delete traverseEnd;
		traverseEnd = nullptr;
		almostEnd -> setNext(nullptr);
		m_size--;
		return(true);
	}

	//return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
