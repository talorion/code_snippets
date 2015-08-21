struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag{};

template<...>
class deque{
public:
	typedef random_access_iterator_tag iterator_category	
};

template<...>
class list{
public:
	typedef bidirectional_iterator_tag iterator_category	
};

template<typename IterT>
struct itertator_traits{
	typedef typename IterT::iterator_category iterator_category
	//...
	};

template<typename T>						//partial template specialisation
struct iterator_traits<T*>					//for build-in pointer types
{
	typedef randon_access_iterator_tag iterator_category
};
