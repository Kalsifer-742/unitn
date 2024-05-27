void bubble_sort_list(node*& head)
{
    int tmp;
	
	bool swapped = true;	
	while(swapped){
		swapped = false;

		node* current = head;
        while (current->next != NULL)
        {
            if(current->value > (current->next)->value)
            {
                tmp = current->value;
                current->value = (current->next)->value;
                (current->next)->value = tmp;
                swapped = true;
            }
            current = current->next;
        }
	}
}