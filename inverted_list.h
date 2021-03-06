// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
#pragma once

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

#include "vector.h"
#include "id.h"


class InvertedList {
public:
    InvertedList(uint64_t nlist, uint64_t dim)
        : nlist_(nlist),
          dim_(dim) {}

public:
    void
    train(const std::vector<VectorPtr> &vectors);

    void
    add(const std::vector<Id> &ids, const std::vector<VectorPtr> &vectors);

    std::pair<Id, float>
    search(const VectorPtr &vector, uint64_t nprobe, uint64_t k);

private:
    uint64_t nlist_;
    uint64_t dim_;
    std::vector<VectorPtr> centroids_;
    std::vector<VectorList> lists_;
    std::vector<IdList> id_lists_;
};
