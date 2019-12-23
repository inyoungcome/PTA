#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef int Position;
typedef struct Node *PtrToNode;
typedef struct Node {
    ElementType x;
    ElementType z;
    PtrToNode Next;
} Node;

typedef Node List;
        

List* read_in();
List* list_add(List* l, List* r);
List* list_mul(List* l, List* r);
void print_list(List *list);

int main(int argc, char* argv[]){
    List* r = NULL;
    List* l = NULL;
//    printf("%d", -5%2);
   l = read_in();
   print_list(l);
//
   r = read_in();
   print_list(r);

//    List *ad = list_add(l,r);
//    print_list(ad);
//
   List *mul = list_mul(l,r);
   print_list(mul);

	return 0; 
}

List* read_in(){
    int num = 0;
    int r = scanf("%d", &num);
    if(r != 1){
        return NULL;
    }

    List* list = (List*) malloc(sizeof(List));
    if(list == NULL){
        return NULL;
    }

    list->Next = NULL;
    list->z = 0;
    list->x = 0;

    PtrToNode last = list ;

    ElementType x = 0,z = 0;
    // r = scanf("%d %d",&x,&z);
    // num -- ;
    while(num > 0 ){
        r = scanf("%d %d",&x,&z);
        PtrToNode node = (PtrToNode) malloc(sizeof(Node));
        if(node == NULL){
            return NULL;
        }
        node->x = x;
        node->z = z;
        node->Next = NULL;
        last ->Next = node;
        last = last->Next;

        num --;
    }

    return list;
}

List* list_add(List* l, List* r){
    List *result = (List*)malloc(sizeof(List));
    if(result == NULL){
        return NULL;
    }
    result ->Next = NULL;

    PtrToNode last = result;

    while(l->Next && r->Next){
        if(l->Next->z > r->Next->z){
            last->Next = l->Next;
            l->Next = l->Next->Next;
            last = last->Next;
            last->Next = NULL;

        }else if(l->Next->z < r->Next->z){
            last->Next = r->Next;
            r->Next = r->Next->Next;
            last = last->Next;
            last->Next = NULL;
        }else{
            l->Next->x += r->Next->x;
            last->Next = l->Next;
            l->Next = l->Next->Next;
            PtrToNode pt = r->Next;
            r->Next = r->Next->Next;
            free(pt);

            last = last->Next;
            last->Next = NULL;

        }
        // switch (((l->Next->z) - (r->Next->z)) > 0)
        // {
        //case :
        //    l->Next->x += r->Next->x;
        //    last->Next = l->Next;
        //    l->Next = l->Next->Next;
        //    PtrToNode pt = r->Next;
        //    r->Next = r->Next->Next;

        //    free(pt);

        //    last = last->Next;
        //    last->Next = NULL;
        //    break;
        //case 0:
        //    last->Next = r->Next;
        //    r->Next = r->Next->Next;
        //    last = last->Next;
        //    last->Next = NULL;
        //    break;
        //case 1:
        //    last->Next = l->Next;
        //    l->Next = l->Next->Next;
        //    last = last->Next;
        //    last->Next = NULL;
        //    break;
        
        //default:
        //    l->Next->x += r->Next->x;
        //    last->Next = l->Next;
        //    l->Next = l->Next->Next;
        //    PtrToNode pt = r->Next;
        //    r->Next = r->Next->Next;

        //    free(pt);

        //    last = last->Next;
        //    last->Next = NULL;
        //    break;
        //}
    }

    last->Next = (r->Next != NULL)?r->Next:l->Next;
    return result;
}

List* list_mul(List* l, List *r){
    List *result = (List*)malloc(sizeof(List));
    if(result == NULL){
        return NULL;
    }
    result ->Next = NULL;
    PtrToNode last = result;

//    PtrToNode last = result;

    PtrToNode pl = l->Next;
    PtrToNode pr = r->Next;
    while(pl){
        while(pr){
            int flag = -1;
            int x = pr->x * pl->x;
            int z = pr->z + pl->z;
            PtrToNode t = result->Next;
            while(t){
                if(t->z == z){
                    t->x += x;
                    // pr = pr->Next;
                    flag = 0;
                    break;
                }else{
                    t = t->Next;
                }
            }
            if(flag = -1){
                PtrToNode r = (PtrToNode)malloc(sizeof(Node));
                // 分配内存失败情况下，还需要释放前期的资源
                if(r == NULL){
                    return NULL;
                }
                r->Next = NULL;
                r->x = x;
                r->z = z;
                last->Next = r;
                last = last->Next;
            }

            pr = pr->Next;
        }
        pl = pl->Next;
    }
    return result;
}

void print_list(List *list){
//    printf("items = %d\n",list->count);
    PtrToNode node = list->Next;
    int count = 0;
    while(node){
    	if(node ->z == 0){
    		printf("(%d) ",node->x);
		}else{
			printf("(%d)X%d ",node->x,node->z);
        		
		}
        node = node->Next;
        count++;
    }
    
    printf("\nitems = %d\n",count);
}
