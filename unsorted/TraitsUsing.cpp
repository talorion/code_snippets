template<typename IterT, typename DistT>								//use this impl for 
void doAdvance(IterT& iter, DistT d, std::random_access_iterator_tag)	// random access
{																		// iterators
	iter+=d;
}

template<typename IterT, typename DistT>								//use this impl for 
void doAdvance(IterT& iter, DistT d, std::bidirectional_iterator_tag)	// bidirectional
{																		// iterators
	if(d >= 0) {while(d--) ++iter;}
	else{while (d++) --iter;}
}

template<typename IterT, typename DistT>								//use this impl for 
void doAdvance(IterT& iter, DistT d, std::input_iterator_tag)			// input
{																		// iterators
	if(d < 0)
	{
		throw std::out_of_range("Negative distance");
	}
	while (d--) ++iter;
}


template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d)
{
	doAdvance(iter, d, typename std::iterator_traits<iterT>::iterator_category());
}