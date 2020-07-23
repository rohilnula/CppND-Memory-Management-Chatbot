#include <iostream>
#include <memory>

#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// MEMORY MANAGEMENT CODE
    ////

    // delete _chatBot;
    std::cout << "Destructing GraphNode ..." << std::endl;

    ////
    //// EOF MEMORY MANAGEMENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// MEMORY MANAGEMENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF MEMORY MANAGEMENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// MEMORY MANAGEMENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF MEMORY MANAGEMENT CODE
}