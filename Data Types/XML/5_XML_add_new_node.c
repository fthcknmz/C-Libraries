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
    
    /* add a new node to the root (current node) */
    xmlNodePtr new_node = xmlNewTextChild(node, NULL, (const xmlChar *)"spouse", (const xmlChar *)"Martha");
    if(new_node==NULL){
        fprintf(stderr,"Unable to create new node\n");
        exit(1);
    }
    /* Save the updated file */
    int r = xmlSaveFormatFile(filename, doc, 0);
    if(r == -1)
        printf("Unable to update and write %s\n",filename);
    else
        printf("%s updated, %d bytes written\n",filename,r);
    
    
    /* clean up */
    xmlFreeDoc(doc);

    return(0);
}

