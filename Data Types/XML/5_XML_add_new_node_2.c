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
    
    /* confirm document root is proper */
    if(xmlStrcmp(node->name, (const xmlChar *)"person") ){
        fprintf(stderr,"%s is NOT of the proper XML type\n",filename);
        xmlFreeDoc(doc);
        exit(1);
    }
    
    /* search for the 'name' node and add a new child, 'middle' along with its contents */
    xmlNodePtr new_node;
    node = node->children;
    while(node!=NULL){
        if(!xmlStrcmp(node->name, (const xmlChar *)"name")){
            new_node = xmlNewTextChild(node, NULL, (const xmlChar *)"middle", (const xmlChar *)"Father of the Country" );
            if(new_node==NULL){
                fprintf(stderr,"Unable to create new node\n");
                exit(1);
            }
            break;
        }
        node = node->next;
    }

    /* Save the updated file */
    int r;
    r = xmlSaveFormatFile(filename, doc, 0);
    if(r == -1)
        printf("Unable to update and write %s\n",filename);
    else
        printf("%s updated, %d bytes written\n",filename,r);
    
    /* clean up */
    xmlFreeDoc(doc);

    return(0);
}

