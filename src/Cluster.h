#pragma once

#include <map>
#include <vector>
#include <set>

#include "LogReader.h"
#include "ComparisonResult.h"

struct NodeData
{
    int NodeNumber;

    // key - FrameNumber
    std::map<size_t, FrameData> Data;
};

class Cluster
{
public:
    bool LoadNodeData();
    bool CompareNodeData(ComparisonResult& TotalResult);

protected:
    void InsertFrameDataIntoCluster(NodeData& InNodeData, FrameData const& InFrameData);
    void Compare(std::vector<FrameData> const& FrameData, ComparisonResult& Result, std::vector<size_t> const& ActorFilter);
    void ProcessDesyncFrameData(std::vector<FrameData> const& InFrameData,
        std::vector<size_t> const& NodeIndices,
        std::vector<size_t> const& ActorFilter, ComparisonResult& Result);

protected:
    std::vector<NodeData> ClusterData;

    std::vector<std::string> NodeFileNames;
    std::set<std::string> AllEntryNames;
};