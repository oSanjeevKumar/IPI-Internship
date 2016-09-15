/*
 * nflc_sxml.h
 * Copyright (C) 2007-2009 ACCESS CO.,LTD.
 * All rights are reserved by ACCESS CO.,LTD.,
 * whether the whole or part of the source code
 * including any modifications is concerned.
 *
 * This is an unpublished source code of ACCESS CO.,LTD., and must be
 * treated as confidential material.  The above copyright notice does
 * not evidence any actual or intended publication of this source code.
 */

/* Copyright (C) 2005, 2006 IP Infusion, Inc. All Rights Reserved.  */

/* Simple XML API.  */

#ifndef NFLC_SXML_H
#define NFLC_SXML_H

#include <expat.h>
#include <nflc_sbuf.h>

/* For avoid dependency to expat.h type.  */
typedef XML_Char sXML_Char;

/* sXML error code.  */
typedef enum
{
  /* Success.  */
  SXML_SUCCESS = 0,

  /* XML parser state error.  */
  SXML_INVALID_STATE_ERR = -1,

  /* Out of memory.  */
  SXML_OUT_OF_MEMORY_ERR = -2,

  /* Other error.  */
  SXML_PARSE_FAILURE = -3

} SXML_ERROR_CODE;

/* XML Attribute.  */
struct _sXML_Attribute
{
  /* Linked list.  */
  struct _sXML_Attribute *next;
  struct _sXML_Attribute *prev;

  /* Attribute name.  */
  slim_char *name;

  /* Attribute value.  */
  slim_char *value;

};

typedef struct _sXML_Attribute sXML_Attribute;

/* sXML structure.  */
struct _sXML
{
  /* Linked list.  */
  struct _sXML *next;
  struct _sXML *prev;

  /* Reference counter.  */
  slim_word reference_counter;

  /* Parent element.  */
  struct _sXML *parent;

  /* Element name.  */
  slim_char *name;

  /* Value. */
  slim_char *value;

  /* Reference XML element.  */
  struct _sXML *ref;

  /* Child elements. */
  /* List(struct _sXML_Element *) list; */
  struct
  {
    struct _sXML *head;
    struct _sXML *tail;
    slim_int count;
  } list;

  /* Attribute list.  */
  /* List(sXML_Attribute *) attrlist; */
  struct
  {
    sXML_Attribute *head;
    sXML_Attribute *tail;
    slim_int count;
  } attrlist;

};

typedef struct _sXML sXML;

/* Typedef sXML for XML element.  */
typedef struct _sXML sXML_Element;

/* XML node for more than one element.  */
struct _sXML_Node 
{
  /* Number of the node.  */
  slim_word max;

  /* Allocation of the index.  */
  slim_word alloced;

/* Initial allocation size of XML node index.  */
#define SXML_NODE_INIT_SIZE   (4)

  /* Index to each element.  */
  void **index;
};

typedef struct _sXML_Node sXML_Node;

slim_char *
xml_parse_escaped_chars(slim_char *in, slim_int size);

/* Macros for getting name, value and node information.  */
#define sXML_Name(N)          ((N)->name)
#define sXML_Value(N)         ((N)->value)
#define sXML_ValueNoEscape(N) (xml_parse_escaped_chars((N)->value, dlna_strlen((N)->value)))
#define sXML_NodeLength(N)    ((N)->max)
#define sXML_NodeItem(N,I)    ((N)->index[I])

/* sXML parse user data.  */
/* Currently XML declaration is not parsed.  Please define
   SXML_XMLDECL_PARSE for declaration parse.  */

/* #define SXML_XMLDECL_PARSE */

/* XML deque structure.  */
struct _sXML_Deque
{
  /* Previous pointer.  */
  struct _sXML_Deque *prev;

  /* sXML element.  */
  sXML *element;
  slim_int element_data_len;
  slim_int element_data_max_len;

};

typedef struct _sXML_Deque sXML_Deque;

/* XML user data structure.  */
struct _sXML_UserData
{
#ifdef SXML_XMLDECL_PARSE
  /* XML version.  */
  slim_char *version;

  /* XML encoding.  */
  slim_char *encoding;
#endif /* SXML_XMLDECL_PARSE */

  /* XML document.  */
  sXML *doc;

  /* Current XML element.  */
  sXML *current;
  slim_int current_len;
  slim_int current_max_len;

  /* Deque of XML element.  */
  sXML_Deque *deque;

  /* Error code.  */
  slim_int error;

  /* Flags.  */
  slim_word flags;
#define SXML_FLAG_CDATA  (1 << 0)

  /* XML parser.  */
  XML_Parser parser;

};

typedef struct _sXML_UserData sXML_UserData;

/* Prototypes.  */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

sXML *
sXML_ElementNew(const slim_char *name, const slim_char *value);

sXML *
sXML_ElementAdd(sXML *e, const slim_char *name,
                const slim_char *value);

sXML *
sXML_ElementAddElement (sXML *e, sXML *add);

sXML *
sXML_ElementDelete(sXML *ele);

sXML_Attribute *
sXML_AttributeAdd(sXML *e, const slim_char *name,
                  const slim_char *value);

void
sXML_AttributeDelete(sXML *e, sXML_Attribute *attr);

void
sXML_AttributeFree(sXML_Attribute *attr);

sXML *
sXML_Lock(sXML *doc);

void
sXML_Unlock(sXML *doc);

void
sXML_NodeFree(sXML_Node *n);

/* Utility function for string compare.  */
slim_int
sXML_NameCmp(const slim_char *a, const slim_char *b);

/* API for XML element lookup.  */
sXML *
sXML_getElement(sXML *ele, slim_char *name);

sXML *
sXML_getFirstElement(sXML *doc);

sXML *
sXML_getFirstElementByTagName (sXML *doc, const slim_char *name);

sXML *
sXML_getFirstElementByTagNameNS(sXML *doc, slim_char *ns, slim_char *name);

slim_char *
sXML_getFirstElementValue(sXML *doc, slim_char *name);

sXML_Attribute *
sXML_getAttribute(sXML *ele, slim_char *name);

sXML_Attribute *
sXML_getFirstAttribute (sXML *ele);

sXML_Attribute *
sXML_getNextAttribute (sXML *ele, sXML_Attribute *in_attr);

slim_char *
sXML_getLocalName(sXML *ele);

slim_char *
sXML_getNamespaceURI(sXML *ele);

/* Multiple elements lookup.  */
slim_int
sXML_getElementsByTagName(sXML *doc, slim_char *name,sXML_Node **out_node);

#ifdef DLNA_DEBUG
/* XML print functions.  */
void
sXML_Print(sXML *doc);
#endif

slim_int
sXML_PrintDocumentStr(sXML *doc, struct sbuf *sbuf);

slim_char *
sXML_PrintDocument(sXML *doc);

slim_char *
sXML_PrintDocument_Escape(sXML *doc);

slim_int
sXML_Copy(sXML *doc, sXML **out_doc);

/* XML parse buffer.  */
slim_int
sXML_ParseMessageInit(sXML_UserData *u);

slim_int
sXML_ParseMessage(sXML_UserData *u, slim_char *buf, slim_word length,
                  slim_int done);

void
sXML_ParseMessageDone(sXML_UserData *u);

/* XML parser.  */
slim_int
sXML_ParseBuffer(slim_char *buf, slim_int length, sXML **doc);

slim_int
sXML_ParseStr(slim_char *str, sXML **doc);

/*!
\par Function:
A generci function which reads whole XML document from a file to a pointer.
\par Parameters:

<table>
	<tr>
		<td>[in]</td>
		<td>folder_path</td>
		<td>Path to folder with XML file.</td>
	</tr>
	<tr>
		<td>[in]</td>
		<td>XML_file_name</td>
		<td>Name of XML file tor read.</td>
	</tr>
	<tr>
		<td>[out]</td>
		<td>doc</td>
		<td>Pointer to a pointer to a read XML document.</td>
	</tr>
</table>

\return Integer value indicating success or failure.

\par Description:
This function notifies the DMS application when a DLNA device is discovered, disconnected, or
updated.

\returnvalue 1 File read successfully.
\returnvalue 0 Failure while reading the file.
 */
slim_int
sXML_ReadXmlFile (const slim_char *folder_path, const slim_char *XML_file_name, sXML **doc);

slim_bool sXML_Boolean (sXML *element);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NFLC_SXML_H */
