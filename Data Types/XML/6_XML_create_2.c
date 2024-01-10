#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

int main(void){
    
    xmlDocPtr doc;

    /* create a new XML document */
    doc = xmlNewDoc((const xmlChar *)"1.0");
    
    if(doc==NULL){
        fprintf(stderr,"Unable to create new XML document\n");
        exit(1);
    }
    
    /* create a new node */
    xmlNodePtr root;
    root = xmlNewDocNode(doc, NULL, (const xmlChar *)"root", NULL);
    if(root==NULL){
        fprintf(stderr,"Unable to create new node\n");
        exit(1);
    }
    
    /* set new node as root element */
    xmlDocSetRootElement(doc, root);

    /* write document */
    int r;
    const char filename[] = "sample2.xml";
    r = xmlSaveFormatFile(filename, doc, 1);
    if(r == -1)
        printf("Unable to create %s\n",filename);
    else
        printf("%s created, %d bytes written\n",filename,r);

    /* cleanup */
    xmlFreeDoc(doc);

    return(0);
}

