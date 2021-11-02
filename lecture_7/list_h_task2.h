template <typename T>
class list
{
private:
  struct Node
  {
    T data;
    Node *next;
    Node(T smth) : data(smth), next(nullptr) {}
  };
  Node *first;
  Node *last;

public:
  list()
  {
    first = nullptr;
    last = nullptr;
  }

  ~list()
  {
    if (first != last)
    {
      Node *currNode = first;
      while (currNode != last)
      {
        Node *copyCurrArd = currNode;
        currNode = currNode->next;
        delete copyCurrArd;
      }
      delete last;
    }
  }

  void pushBack(T data)
  {
    Node *newNode = new Node(data);
    if (!first)
    {
      first = newNode;
      last = newNode;
    }
    else
    {
      last->next = newNode;
      last = newNode;
    }
  }

  void InsertNode(T data, int position)
  {
    Node *newNode = new Node(data);
    if (!first && position != 0)
      pushBack(CreateNode(T()));

    Node *currNode = first;
    int index = 0;

    while (index < position - 1)
    {
      if (!(currNode->next))
        pushBack(CreateNode(T()));
      currNode = currNode->next;
      index += 1;
    }
    if (currNode != first || position == 1)
    {
      Node *copyCurrNodeNextAdr = currNode->next;
      currNode->next = newNode;
      newNode->next = copyCurrNodeNextAdr;
    }
    else
    {
      Node *copyFirstAddr = first;
      first = newNode;
      newNode->next = copyFirstAddr;
    }
  }

  void InsertStructNode(T data, int position, T nulldata)
  {
    Node *newNode = new Node(data);

    if (!first && position != 0)
      pushBack(nulldata);

    Node *currNode = first;
    int index = 0;

    while (index < position - 1)
    {
      if (!(currNode->next))
        pushBack(nulldata);
      currNode = currNode->next;
      index += 1;
    }
    if (currNode != first || position == 1)
    {
      Node *copyCurrNodeNextAdr = currNode->next;
      currNode->next = newNode;
      newNode->next = copyCurrNodeNextAdr;
    }
    else
    {
      Node *copyFirstAddr = first;
      first = newNode;
      newNode->next = copyFirstAddr;
    }
  }

  void RemoveNode(int index)
  {

    if (index == 0)
    {
      Node *copyFirstLink = first;
      first = first->next;
      delete copyFirstLink;
    }
    else
    {
      Node *currNode = first;
      int currId = 0;
      while (currId < index - 1)
      {
        currNode = currNode->next;
        currId += 1;
      }
      if (currNode->next != last)
      {
        Node *NodeToLinkFrom = currNode;
        currNode = currNode->next;
        Node *NodeToLinkTo = currNode->next;
        delete currNode;
        NodeToLinkFrom->next = NodeToLinkTo;
      }
      else
      {
        Node *firstBeforeLastElem = currNode;
        currNode = currNode->next;
        delete currNode;
        firstBeforeLastElem->next = nullptr;
        last = firstBeforeLastElem;
      }
    }
  }
  
  T GetElement(size_t position)
  {
    Node *currNode = first;
    int index = 0;
    while (index < position)
    {
      currNode = currNode->next;
      index += 1;
    }
    return (currNode->data);
  }

  auto GetFullElement(size_t position)
  {
    Node *currNode = first;
    int index = 0;
    while (index < position)
    {
      currNode = currNode->next;
      index += 1;
    }
    return currNode;
  }

  int listSize()
  {
    Node *currElement = first;
    int count = 0;
    while (currElement)
    {
      count += 1;
      currElement = currElement->next;
    }
    return count;
  }

  void changeNodeVal(T newData, int index)
  {
    Node* newNode = CreateNode(newData);
    Node *currNode = first;
    int position = 0;
    while (position != index)
    {
      currNode = currNode->next;
      //std::cout<<"\ndebug: "<<currNode->data;
      position++;
    }
    currNode->data = newNode->data;
  }

  void PrintList()
  {
    Node *currElement = first;
    while (currElement) // currElement != nullptr
    {
      std::cout << currElement->data << " " << currElement << std::endl;
      currElement = currElement->next;
    }
  }

  void PrintStructList()
  {
    Node *currElement = first;
    while (currElement) // currElement != nullptr
    {
      std::cout << " "<<((currElement->data).data) << " " << ((currElement->data).count) << ";";
      currElement = currElement->next;
    }
  }

  Node *CreateNode(T data)
  {
    Node *newNode = new Node(data);
    return newNode;
  }

  bool isVoid()
  {
    return !first;
  }
};
