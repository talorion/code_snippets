//(1 + 2) * (3 + 4)

class Expression{
public:
	virtual ~Expression();
	virtual double evaluate() =0;
};

class NumberExpression : public Expression{
public:
	NumberExpression(double value):
		value_(value)
	{}
	
	virtual double evaluate() { return value_;}
	
private:
	double value_;
};

class AdditionExpression : public Expression{
public: 
	AdditionalExpression (Expression* left, Expression* right):
		left_(left),
		right_(right)
	{}
	
	virtual double evaluate(){
		//Evaluates the operants
		double left = left_->evaluate();
		double right = right_->evaluate();
		
		// add them.
		return left+right;
	}
	
private:
	Expression* left_;
	Expressoin* right_;
};
