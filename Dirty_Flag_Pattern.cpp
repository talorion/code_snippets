class Transform{
public:
	//get an object's world transform by combining all the local transforms along its parent chain
	static Transform origin();
	
	Transform combine(Transform& other);
};

class GraphNode{
public:
	GraphNode(Mesh* mesh):
		mesh_(mesh),
		local(Transform::origin()),
		dirty(true)
	{}
	
	void setTransform(Transform local){
		local_ = local;
		dirty_ = true;
	}
	
	void render(Transform transform, bool dirty){
	
		dirty |= dirty_;
		if(dirty){
			Transform world = local_combine(parentWorld);
			dirty_ = false;
		}
		
		if(mesh_) renderMesh(mesh_, world);
		
		for(int i=0; i<numChildren_; ++i){
			children_[i]->render(world, dirty);
		}
	}

private:
	Transform world_;
	bool dirty_;

	Transform local_;
	Mesh* mesh_;
	
	GraphNode* children_[MAX_CHILDREN];
	int numChildren_;
};

void renderMesh(Mesh* mesh; Transform transform);

int main(){
	GraphNode* graph_ = new GraphNode(NULL);
	// Add children to root graph node ...
	
	//draw an entire scene graph
	graph_->render(Transform::origin());
	
	return 0;
}