class Investment{ /*…*/ }; //root class of hirachy of investment Types

void f()
{
	std::tr1::shared_ptr<Investment> pInv1(crateInvestment());//pInvl points to the object returned from crateInvestment
	std::tr1::shared_ptr<Investment> pInv2(pInv1); // both pInv1 and pInvl2 now point tothe object
	pInv1 = pInv2;// ditto –nothing has changed
}//pInv1 and pInvl2  are destroyed, and the object they point to is automatically deleted
