#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

static void dump_elements(xmlNodePtr n){
    xmlNodePtr nodePtr;
    xmlChar *attribute;
    
    /* loop through all nodes */
    for(nodePtr = n; nodePtr; nodePtr=nodePtr->next ){
        if( nodePtr->type == XML_ELEMENT_NODE )
            printf("Node: %s\n",nodePtr->name);         /* output node name */
        
        attribute = xmlGetProp(nodePtr,(const xmlChar *)"type");
        if( attribute!=NULL )
            printf(" Attribute: %s \n",attribute);  /* output the attribute if avilable */
        xmlFree(attribute);
        
        dump_elements(nodePtr->children);
    }
}

int main(int argc, const char * argv[]) {
    
    const char filename[] = "/Users/fthcknmz/Documents/Data Structures/Data Structures/sample1.xml";
    
    /* parse the XML file*/
    xmlDocPtr doc;
    doc = xmlParseFile(filename);
    if(doc==NULL){
        fprintf(stderr,"Unable to parse document %s\n",filename);
        exit(1);
    }
    
    /* fetch the root element */
    xmlNodePtr node;
    node = xmlDocGetRootElement(doc);
    if( node==NULL ){
        fprintf(stderr,"Document %s is empty\n",filename);
        xmlFreeDoc(doc);
        exit(1);
    }
    
    /* recursively display all elements in the file */
    dump_elements(node);


    /* clean up */
    xmlFreeDoc(doc);

    return(0);
}

