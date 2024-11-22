#include "Document.h"

const std::string& Document::getText () const
{
    return text;
}

std::size_t Document::getId () const
{
    return id;
}

void Document::print () const
{
    std::cout << "id: " << id << "\n\t text: " << text << std::endl;
}