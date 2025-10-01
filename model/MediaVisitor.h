#ifndef MEDIAVISITOR_H
#define MEDIAVISITOR_H

class Book;
class Film;
class Article;

class MediaVisitor {
public:
    virtual void visit(const Book *book) = 0;
    virtual void visit(const Film *film) = 0;
    virtual void visit(const Article *article) = 0;

    virtual void visitEdit(const Book *book) = 0;
    virtual void visitEdit(const Film *film) = 0;
    virtual void visitEdit(const Article *article) = 0;
};

#endif
