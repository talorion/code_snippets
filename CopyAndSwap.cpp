class CopyAndSwap
{
private:
	//...
	void swap (CopyAndSwap&); 	//exchange *this’s and rhs’s data
	//...				//see item 29 for details
};

CopyAndSwap& CopyAndSwap::operator=(const CopyAndSwap& rhs)
{
	CopyAndSwap temp(rhs);	// make a copy of rhs’s data
	swap(temp); 		//swap this’s data with the copy’s
	return *this;
}