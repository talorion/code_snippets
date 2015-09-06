class PrettyMenu
{
	//...
	std::tr1::shared_ptr<Image> bgImage;
	//...
};

void PrettyMenu::changeBackground(std::istream& imgSrc)
{
	Lock (&mutex); //replace bgImag’s internal
	bgImage.reset(new Image(imgSrc)); //pointer with the result of the
	++imageChanges; //“new“ Image expression
}
