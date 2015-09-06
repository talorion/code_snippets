class GameCharacter
{
public:
	int healthValue() const
{
		//… 				//do before stuff
		int  retval = doHealthValue(); 	// do real Work
		//…				// do after stuff
		return retval;
}
private:
	virtual int doHealthValue() const	// derived classes may redefine this
{					// defaults algorithm for calculationg 
					//characters health.
}
};
