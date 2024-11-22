#include "DocumentStore.h"

// Constructor with just a size :
DocumentStore::DocumentStore(std::size_t s):
    docs(s), docsDraft(DRAFT_SIZE), size(s), curr(0), currDraft(0)
{}
// s documents that are empty (in docs : contains completed documents) ;
// docsDraft contains the draft documents, and its size is fixed to DRAFT_SIZE = 10.

// COPY-CONSTRUCTOR :
DocumentStore::DocumentStore(const DocumentStore &rhs):
    docs(rhs.docs), docsDraft(DRAFT_SIZE), size(rhs.size), curr(rhs.curr), currDraft(rhs.currDraft)
{}
// Completed documents must be copied between DocumentStores ;
// drafts must not be transferred during the operation but just emptied.

// COPY-ASSIGNMENT OPERATOR
DocumentStore& DocumentStore::operator=(const DocumentStore &rhs) {
    docs = rhs.docs;
    docsDraft = std::vector<Document>(DRAFT_SIZE);
    size = rhs.size;
    curr = rhs.curr;
    currDraft = 0;
    return *this; // Because the operator= wants you to return a pointer.
}

void DocumentStore::addDocument (const Document& doc)
{
    // We have to check if the number of the document is < the size :
    if (curr < size) {
        docs[curr] = doc;
        curr++;
        // Identical : docs[curr++] = doc;
        // Don't use push_back : we aren't building size-changing vectors !
    }
}

void DocumentStore::saveAsDraft (const Document& draft)
{
    if (currDraft < DRAFT_SIZE) {
        docsDraft[currDraft++] = draft;
    }
}

void DocumentStore::print () const
{
    std::cout << "List of Documents:" << std::endl;
    for (std::size_t j = 0; j < curr; ++j)
        docs[j].print();

    std::cout << "List of Drafts:" << std::endl;
    for (std::size_t j = 0; j < currDraft; ++j)
        docsDraft[j].print();
}
