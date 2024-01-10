#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

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
    if(node==NULL){
        fprintf(stderr,"Document %s is empty\n",filename);
        xmlFreeDoc(doc);
        exit(1);
    }
    
    /* fetch a specific node */
    xmlChar *key;
    node = node->children;
    while(node != NULL){
        if(!xmlStrcmp(node->name, (const xmlChar *)"notes")){
            printf("Found node '%s'\n",node->name); // print the name of node
            
            key = xmlNodeListGetString(doc, node->children, 1);
            printf("Value of 'notes': %s\n",key);
            xmlFree(key);
            
        }
        node = node->next;
    }
    
    /* clean up */
    xmlFreeDoc(doc);

    return(0);
}

