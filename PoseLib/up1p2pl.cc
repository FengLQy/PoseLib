// Copyright (c) 2020, Viktor Larsson
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of the copyright holder nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "up1p2pl.h"
#include "univariate.h"

int pose_lib::up1p2pl(const std::vector<Eigen::Vector3d> &xp, const std::vector<Eigen::Vector3d> &Xp,
                      const std::vector<Eigen::Vector3d> &x, const std::vector<Eigen::Vector3d> &X0,
                      const std::vector<Eigen::Vector3d> &V, CameraPoseVector *output) {

    Eigen::Matrix<double, 3, 2> X;
    X << X0[0] - Xp[0], X0[1] - Xp[0];

    const double c0 = V[0](0) * V[1](0) * X(1, 0) * x[1](1) * x[0](2) * xp[0](2) + V[0](0) * V[1](0) * X(2, 0) * x[0](1) * x[1](1) * xp[0](2) + V[0](0) * V[1](1) * X(1, 0) * x[1](0) * x[0](2) * xp[0](2) + V[0](0) * V[1](1) * X(2, 0) * x[1](0) * x[0](1) * xp[0](2) - V[1](0) * V[0](1) * X(0, 0) * x[1](1) * x[0](2) * xp[0](2) + V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](1) * xp[0](2) - V[1](0) * V[0](2) * X(0, 0) * x[0](1) * x[1](1) * xp[0](2) - V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](2) - V[0](1) * V[1](1) * X(0, 0) * x[1](0) * x[0](2) * xp[0](2) + V[0](1) * V[1](1) * X(2, 0) * x[0](0) * x[1](0) * xp[0](2) - V[1](1) * V[0](2) * X(0, 0) * x[1](0) * x[0](1) * xp[0](2) - V[1](1) * V[0](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](2) - V[0](0) * V[1](0) * X(1, 1) * x[0](1) * x[1](2) * xp[0](2) - V[0](0) * V[1](0) * X(2, 1) * x[0](1) * x[1](1) * xp[0](2) + V[0](0) * V[1](1) * X(0, 1) * x[0](1) * x[1](2) * xp[0](2) - V[0](0) * V[1](1) * X(2, 1) * x[1](0) * x[0](1) * xp[0](2) + V[0](0) * V[1](2) * X(0, 1) * x[0](1) * x[1](1) * xp[0](2) + V[0](0) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](2) - V[1](0) * V[0](1) * X(1, 1) * x[0](0) * x[1](2) * xp[0](2) - V[1](0) * V[0](1) * X(2, 1) * x[0](0) * x[1](1) * xp[0](2) + V[0](1) * V[1](1) * X(0, 1) * x[0](0) * x[1](2) * xp[0](2) - V[0](1) * V[1](1) * X(2, 1) * x[0](0) * x[1](0) * xp[0](2) + V[0](1) * V[1](2) * X(0, 1) * x[0](0) * x[1](1) * xp[0](2) + V[0](1) * V[1](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](2) - V[0](0) * V[1](0) * X(1, 0) * x[0](2) * x[1](2) * xp[0](1) - V[0](0) * V[1](0) * X(2, 0) * x[0](1) * x[1](2) * xp[0](1) + V[0](0) * V[1](2) * X(1, 0) * x[1](0) * x[0](2) * xp[0](1) + V[0](0) * V[1](2) * X(2, 0) * x[1](0) * x[0](1) * xp[0](1) + V[1](0) * V[0](1) * X(0, 0) * x[0](2) * x[1](2) * xp[0](1) - V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](2) * xp[0](1) + V[1](0) * V[0](2) * X(0, 0) * x[0](1) * x[1](2) * xp[0](1) + V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](2) * xp[0](1) - V[0](1) * V[1](2) * X(0, 0) * x[1](0) * x[0](2) * xp[0](1) + V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](0) * xp[0](1) - V[0](2) * V[1](2) * X(0, 0) * x[1](0) * x[0](1) * xp[0](1) - V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](1) + V[0](0) * V[1](0) * X(1, 1) * x[0](2) * x[1](2) * xp[0](1) + V[0](0) * V[1](0) * X(2, 1) * x[1](1) * x[0](2) * xp[0](1) - V[0](0) * V[1](1) * X(0, 1) * x[0](2) * x[1](2) * xp[0](1) + V[0](0) * V[1](1) * X(2, 1) * x[1](0) * x[0](2) * xp[0](1) - V[0](0) * V[1](2) * X(0, 1) * x[1](1) * x[0](2) * xp[0](1) - V[0](0) * V[1](2) * X(1, 1) * x[1](0) * x[0](2) * xp[0](1) - V[1](0) * V[0](2) * X(1, 1) * x[0](0) * x[1](2) * xp[0](1) - V[1](0) * V[0](2) * X(2, 1) * x[0](0) * x[1](1) * xp[0](1) + V[1](1) * V[0](2) * X(0, 1) * x[0](0) * x[1](2) * xp[0](1) - V[1](1) * V[0](2) * X(2, 1) * x[0](0) * x[1](0) * xp[0](1) + V[0](2) * V[1](2) * X(0, 1) * x[0](0) * x[1](1) * xp[0](1) + V[0](2) * V[1](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](1) - V[0](0) * V[1](1) * X(1, 0) * x[0](2) * x[1](2) * xp[0](0) - V[0](0) * V[1](1) * X(2, 0) * x[0](1) * x[1](2) * xp[0](0) - V[0](0) * V[1](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](0) - V[0](0) * V[1](2) * X(2, 0) * x[0](1) * x[1](1) * xp[0](0) + V[0](1) * V[1](1) * X(0, 0) * x[0](2) * x[1](2) * xp[0](0) - V[0](1) * V[1](1) * X(2, 0) * x[0](0) * x[1](2) * xp[0](0) + V[0](1) * V[1](2) * X(0, 0) * x[1](1) * x[0](2) * xp[0](0) - V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](1) * xp[0](0) + V[1](1) * V[0](2) * X(0, 0) * x[0](1) * x[1](2) * xp[0](0) + V[1](1) * V[0](2) * X(1, 0) * x[0](0) * x[1](2) * xp[0](0) + V[0](2) * V[1](2) * X(0, 0) * x[0](1) * x[1](1) * xp[0](0) + V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](0) + V[1](0) * V[0](1) * X(1, 1) * x[0](2) * x[1](2) * xp[0](0) + V[1](0) * V[0](1) * X(2, 1) * x[1](1) * x[0](2) * xp[0](0) + V[1](0) * V[0](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](0) + V[1](0) * V[0](2) * X(2, 1) * x[0](1) * x[1](1) * xp[0](0) - V[0](1) * V[1](1) * X(0, 1) * x[0](2) * x[1](2) * xp[0](0) + V[0](1) * V[1](1) * X(2, 1) * x[1](0) * x[0](2) * xp[0](0) - V[0](1) * V[1](2) * X(0, 1) * x[1](1) * x[0](2) * xp[0](0) - V[0](1) * V[1](2) * X(1, 1) * x[1](0) * x[0](2) * xp[0](0) - V[1](1) * V[0](2) * X(0, 1) * x[0](1) * x[1](2) * xp[0](0) + V[1](1) * V[0](2) * X(2, 1) * x[1](0) * x[0](1) * xp[0](0) - V[0](2) * V[1](2) * X(0, 1) * x[0](1) * x[1](1) * xp[0](0) - V[0](2) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](0);
    const double c1 = 2 * V[1](0) * V[0](1) * X(0, 0) * x[0](0) * x[1](1) * xp[0](2) - 2 * V[0](0) * V[1](1) * X(1, 0) * x[0](0) * x[1](0) * xp[0](2) - 2 * V[0](0) * V[1](0) * X(1, 0) * x[0](0) * x[1](1) * xp[0](2) + 2 * V[0](1) * V[1](1) * X(0, 0) * x[0](0) * x[1](0) * xp[0](2) + 2 * V[0](0) * V[1](0) * X(1, 1) * x[1](0) * x[0](1) * xp[0](2) - 2 * V[0](0) * V[1](1) * X(0, 1) * x[1](0) * x[0](1) * xp[0](2) + 2 * V[1](0) * V[0](1) * X(1, 1) * x[0](0) * x[1](0) * xp[0](2) - 2 * V[0](1) * V[1](1) * X(0, 1) * x[0](0) * x[1](0) * xp[0](2) + 2 * V[0](0) * V[1](0) * X(1, 0) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[0](0) * V[1](0) * X(1, 0) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[0](0) * V[1](0) * X(2, 0) * x[1](0) * x[0](1) * xp[0](1) - 2 * V[0](0) * V[1](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[1](0) * V[0](1) * X(0, 0) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[1](0) * V[0](1) * X(0, 0) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(0, 0) * x[1](0) * x[0](1) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[0](1) * V[1](2) * X(0, 0) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[0](0) * V[1](0) * X(1, 1) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[0](0) * V[1](0) * X(1, 1) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](0) * V[1](0) * X(2, 1) * x[0](0) * x[1](1) * xp[0](1) + 2 * V[0](0) * V[1](1) * X(0, 1) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[0](0) * V[1](1) * X(0, 1) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](0) * V[1](1) * X(2, 1) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[0](0) * V[1](2) * X(0, 1) * x[0](0) * x[1](1) * xp[0](1) + 2 * V[0](0) * V[1](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[1](0) * V[0](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[1](1) * V[0](2) * X(0, 1) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[0](0) * V[1](0) * X(1, 0) * x[1](1) * x[0](2) * xp[0](0) - 2 * V[0](0) * V[1](0) * X(2, 0) * x[0](1) * x[1](1) * xp[0](0) + 2 * V[0](0) * V[1](1) * X(1, 0) * x[0](0) * x[1](2) * xp[0](0) + 2 * V[0](0) * V[1](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](0) + 2 * V[1](0) * V[0](1) * X(0, 0) * x[1](1) * x[0](2) * xp[0](0) - 2 * V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](1) * xp[0](0) + 2 * V[1](0) * V[0](2) * X(0, 0) * x[0](1) * x[1](1) * xp[0](0) + 2 * V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](0) - 2 * V[0](1) * V[1](1) * X(0, 0) * x[0](0) * x[1](2) * xp[0](0) - 2 * V[0](1) * V[1](2) * X(0, 0) * x[0](0) * x[1](1) * xp[0](0) + 2 * V[0](0) * V[1](0) * X(1, 1) * x[0](1) * x[1](2) * xp[0](0) + 2 * V[0](0) * V[1](0) * X(2, 1) * x[0](1) * x[1](1) * xp[0](0) - 2 * V[0](0) * V[1](1) * X(0, 1) * x[0](1) * x[1](2) * xp[0](0) + 2 * V[0](0) * V[1](1) * X(2, 1) * x[1](0) * x[0](1) * xp[0](0) - 2 * V[0](0) * V[1](2) * X(0, 1) * x[0](1) * x[1](1) * xp[0](0) - 2 * V[0](0) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](0) - 2 * V[1](0) * V[0](1) * X(1, 1) * x[1](0) * x[0](2) * xp[0](0) - 2 * V[1](0) * V[0](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](0) + 2 * V[0](1) * V[1](1) * X(0, 1) * x[1](0) * x[0](2) * xp[0](0) + 2 * V[1](1) * V[0](2) * X(0, 1) * x[1](0) * x[0](1) * xp[0](0) - 2 * V[0](0) * V[1](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](2) - 2 * V[0](0) * V[1](2) * X(2, 0) * x[0](1) * x[1](1) * xp[0](2) + 2 * V[1](0) * V[0](1) * X(2, 0) * x[1](1) * x[0](2) * xp[0](2) - 2 * V[1](0) * V[0](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](2) + 2 * V[0](1) * V[1](1) * X(2, 0) * x[1](0) * x[0](2) * xp[0](2) + 2 * V[0](1) * V[1](2) * X(0, 0) * x[1](1) * x[0](2) * xp[0](2) - 2 * V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](1) * xp[0](2) - 2 * V[1](1) * V[0](2) * X(1, 0) * x[1](0) * x[0](2) * xp[0](2) + 2 * V[0](2) * V[1](2) * X(0, 0) * x[0](1) * x[1](1) * xp[0](2) + 2 * V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](2) - 2 * V[0](0) * V[1](1) * X(2, 1) * x[0](1) * x[1](2) * xp[0](2) + 2 * V[0](0) * V[1](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](2) + 2 * V[1](0) * V[0](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](2) + 2 * V[1](0) * V[0](2) * X(2, 1) * x[0](1) * x[1](1) * xp[0](2) - 2 * V[0](1) * V[1](1) * X(2, 1) * x[0](0) * x[1](2) * xp[0](2) + 2 * V[0](1) * V[1](2) * X(1, 1) * x[0](0) * x[1](2) * xp[0](2) - 2 * V[1](1) * V[0](2) * X(0, 1) * x[0](1) * x[1](2) * xp[0](2) + 2 * V[1](1) * V[0](2) * X(2, 1) * x[1](0) * x[0](1) * xp[0](2) - 2 * V[0](2) * V[1](2) * X(0, 1) * x[0](1) * x[1](1) * xp[0](2) - 2 * V[0](2) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](2) + 2 * V[0](0) * V[1](2) * X(1, 0) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[0](0) * V[1](2) * X(2, 0) * x[0](1) * x[1](2) * xp[0](1) - 2 * V[1](0) * V[0](1) * X(2, 0) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[1](0) * V[0](2) * X(1, 0) * x[0](2) * x[1](2) * xp[0](1) - 2 * V[0](1) * V[1](2) * X(0, 0) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[0](1) * V[1](2) * X(2, 0) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](2) * V[1](2) * X(0, 0) * x[0](1) * x[1](2) * xp[0](1) - 2 * V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[0](2) * V[1](2) * X(1, 0) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[0](0) * V[1](1) * X(2, 1) * x[0](2) * x[1](2) * xp[0](1) - 2 * V[0](0) * V[1](2) * X(1, 1) * x[0](2) * x[1](2) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(1, 1) * x[0](2) * x[1](2) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(2, 1) * x[1](1) * x[0](2) * xp[0](1) + 2 * V[1](1) * V[0](2) * X(0, 1) * x[0](2) * x[1](2) * xp[0](1) - 2 * V[1](1) * V[0](2) * X(2, 1) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[1](1) * V[0](2) * X(2, 1) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[0](2) * V[1](2) * X(0, 1) * x[1](1) * x[0](2) * xp[0](1) + 2 * V[0](2) * V[1](2) * X(1, 1) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[0](2) * V[1](2) * X(1, 1) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](1) * V[1](1) * X(2, 0) * x[0](2) * x[1](2) * xp[0](0) - 2 * V[0](1) * V[1](2) * X(2, 0) * x[1](1) * x[0](2) * xp[0](0) + 2 * V[1](1) * V[0](2) * X(1, 0) * x[0](2) * x[1](2) * xp[0](0) + 2 * V[0](2) * V[1](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](0) + 2 * V[0](1) * V[1](1) * X(2, 1) * x[0](2) * x[1](2) * xp[0](0) - 2 * V[0](1) * V[1](2) * X(1, 1) * x[0](2) * x[1](2) * xp[0](0) + 2 * V[1](1) * V[0](2) * X(2, 1) * x[0](1) * x[1](2) * xp[0](0) - 2 * V[0](2) * V[1](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](0);
    const double c2 = 4 * V[1](0) * V[0](1) * X(0, 0) * x[0](0) * x[1](0) * xp[0](1) - 4 * V[0](0) * V[1](0) * X(1, 0) * x[0](0) * x[1](0) * xp[0](1) + 4 * V[0](0) * V[1](0) * X(1, 1) * x[0](0) * x[1](0) * xp[0](1) - 4 * V[0](0) * V[1](1) * X(0, 1) * x[0](0) * x[1](0) * xp[0](1) + 4 * V[0](0) * V[1](0) * X(1, 0) * x[0](0) * x[1](1) * xp[0](0) - 4 * V[1](0) * V[0](1) * X(0, 0) * x[0](0) * x[1](1) * xp[0](0) - 4 * V[0](0) * V[1](0) * X(1, 1) * x[1](0) * x[0](1) * xp[0](0) + 4 * V[0](0) * V[1](1) * X(0, 1) * x[1](0) * x[0](1) * xp[0](0) - 2 * V[0](0) * V[1](0) * X(1, 0) * x[1](1) * x[0](2) * xp[0](2) + 2 * V[0](0) * V[1](1) * X(2, 0) * x[1](0) * x[0](1) * xp[0](2) + 4 * V[0](0) * V[1](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](2) + 2 * V[1](0) * V[0](1) * X(0, 0) * x[1](1) * x[0](2) * xp[0](2) - 2 * V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](1) * xp[0](2) + 2 * V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](2) - 4 * V[0](1) * V[1](2) * X(0, 0) * x[0](0) * x[1](1) * xp[0](2) - 2 * V[1](1) * V[0](2) * X(0, 0) * x[1](0) * x[0](1) * xp[0](2) + 2 * V[0](0) * V[1](0) * X(1, 1) * x[0](1) * x[1](2) * xp[0](2) - 2 * V[0](0) * V[1](1) * X(0, 1) * x[0](1) * x[1](2) * xp[0](2) + 2 * V[0](0) * V[1](1) * X(2, 1) * x[1](0) * x[0](1) * xp[0](2) - 2 * V[0](0) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](2) - 2 * V[1](0) * V[0](1) * X(2, 1) * x[0](0) * x[1](1) * xp[0](2) - 4 * V[1](0) * V[0](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](2) + 2 * V[0](1) * V[1](2) * X(0, 1) * x[0](0) * x[1](1) * xp[0](2) + 4 * V[1](1) * V[0](2) * X(0, 1) * x[1](0) * x[0](1) * xp[0](2) + 2 * V[0](0) * V[1](0) * X(1, 0) * x[0](2) * x[1](2) * xp[0](1) - 4 * V[0](0) * V[1](2) * X(1, 0) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[0](0) * V[1](2) * X(1, 0) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[1](0) * V[0](1) * X(0, 0) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](2) * xp[0](1) + 4 * V[1](0) * V[0](1) * X(2, 0) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](2) * xp[0](1) - 4 * V[1](0) * V[0](2) * X(1, 0) * x[1](0) * x[0](2) * xp[0](1) + 4 * V[0](1) * V[1](2) * X(0, 0) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[0](1) * V[1](2) * X(0, 0) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[0](0) * V[1](0) * X(1, 1) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[0](0) * V[1](1) * X(0, 1) * x[0](2) * x[1](2) * xp[0](1) - 4 * V[0](0) * V[1](1) * X(2, 1) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[0](0) * V[1](1) * X(2, 1) * x[1](0) * x[0](2) * xp[0](1) + 4 * V[0](0) * V[1](2) * X(1, 1) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[0](0) * V[1](2) * X(1, 1) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[1](0) * V[0](2) * X(1, 1) * x[0](0) * x[1](2) * xp[0](1) + 4 * V[1](0) * V[0](2) * X(1, 1) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[1](1) * V[0](2) * X(0, 1) * x[0](0) * x[1](2) * xp[0](1) - 4 * V[1](1) * V[0](2) * X(0, 1) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[1](1) * V[0](2) * X(2, 1) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[0](2) * V[1](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[0](0) * V[1](1) * X(2, 0) * x[0](1) * x[1](2) * xp[0](0) + 2 * V[0](0) * V[1](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](0) - 4 * V[1](0) * V[0](1) * X(2, 0) * x[1](1) * x[0](2) * xp[0](0) + 4 * V[1](0) * V[0](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](0) - 2 * V[0](1) * V[1](2) * X(0, 0) * x[1](1) * x[0](2) * xp[0](0) + 2 * V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](1) * xp[0](0) + 2 * V[1](1) * V[0](2) * X(0, 0) * x[0](1) * x[1](2) * xp[0](0) - 2 * V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](0) + 4 * V[0](0) * V[1](1) * X(2, 1) * x[0](1) * x[1](2) * xp[0](0) - 4 * V[0](0) * V[1](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](0) + 2 * V[1](0) * V[0](1) * X(2, 1) * x[1](1) * x[0](2) * xp[0](0) - 2 * V[1](0) * V[0](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](0) - 2 * V[0](1) * V[1](2) * X(0, 1) * x[1](1) * x[0](2) * xp[0](0) + 2 * V[1](1) * V[0](2) * X(0, 1) * x[0](1) * x[1](2) * xp[0](0) - 2 * V[1](1) * V[0](2) * X(2, 1) * x[1](0) * x[0](1) * xp[0](0) + 2 * V[0](2) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](0) - 4 * V[0](1) * V[1](2) * X(2, 0) * x[1](1) * x[0](2) * xp[0](2) + 4 * V[0](2) * V[1](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](2) + 4 * V[1](1) * V[0](2) * X(2, 1) * x[0](1) * x[1](2) * xp[0](2) - 4 * V[0](2) * V[1](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](2) + 4 * V[0](1) * V[1](2) * X(2, 0) * x[0](2) * x[1](2) * xp[0](1) - 4 * V[0](2) * V[1](2) * X(1, 0) * x[0](2) * x[1](2) * xp[0](1) - 4 * V[1](1) * V[0](2) * X(2, 1) * x[0](2) * x[1](2) * xp[0](1) + 4 * V[0](2) * V[1](2) * X(1, 1) * x[0](2) * x[1](2) * xp[0](1);
    const double c3 = 2 * V[0](0) * V[1](0) * X(1, 0) * x[0](0) * x[1](1) * xp[0](2) - 2 * V[0](0) * V[1](1) * X(1, 0) * x[0](0) * x[1](0) * xp[0](2) - 2 * V[1](0) * V[0](1) * X(0, 0) * x[0](0) * x[1](1) * xp[0](2) + 2 * V[0](1) * V[1](1) * X(0, 0) * x[0](0) * x[1](0) * xp[0](2) - 2 * V[0](0) * V[1](0) * X(1, 1) * x[1](0) * x[0](1) * xp[0](2) + 2 * V[0](0) * V[1](1) * X(0, 1) * x[1](0) * x[0](1) * xp[0](2) + 2 * V[1](0) * V[0](1) * X(1, 1) * x[0](0) * x[1](0) * xp[0](2) - 2 * V[0](1) * V[1](1) * X(0, 1) * x[0](0) * x[1](0) * xp[0](2) - 2 * V[0](0) * V[1](0) * X(1, 0) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[0](0) * V[1](0) * X(1, 0) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[0](0) * V[1](0) * X(2, 0) * x[1](0) * x[0](1) * xp[0](1) + 2 * V[0](0) * V[1](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[1](0) * V[0](1) * X(0, 0) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[1](0) * V[0](1) * X(0, 0) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(0, 0) * x[1](0) * x[0](1) * xp[0](1) + 2 * V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[0](1) * V[1](2) * X(0, 0) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[0](0) * V[1](0) * X(1, 1) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[0](0) * V[1](0) * X(1, 1) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](0) * V[1](0) * X(2, 1) * x[0](0) * x[1](1) * xp[0](1) - 2 * V[0](0) * V[1](1) * X(0, 1) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[0](0) * V[1](1) * X(0, 1) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[0](0) * V[1](1) * X(2, 1) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[0](0) * V[1](2) * X(0, 1) * x[0](0) * x[1](1) * xp[0](1) - 2 * V[0](0) * V[1](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[1](1) * V[0](2) * X(0, 1) * x[0](0) * x[1](0) * xp[0](1) + 2 * V[0](0) * V[1](0) * X(1, 0) * x[1](1) * x[0](2) * xp[0](0) - 2 * V[0](0) * V[1](0) * X(2, 0) * x[0](1) * x[1](1) * xp[0](0) + 2 * V[0](0) * V[1](1) * X(1, 0) * x[0](0) * x[1](2) * xp[0](0) - 2 * V[0](0) * V[1](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](0) - 2 * V[1](0) * V[0](1) * X(0, 0) * x[1](1) * x[0](2) * xp[0](0) + 2 * V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](1) * xp[0](0) + 2 * V[1](0) * V[0](2) * X(0, 0) * x[0](1) * x[1](1) * xp[0](0) - 2 * V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](0) - 2 * V[0](1) * V[1](1) * X(0, 0) * x[0](0) * x[1](2) * xp[0](0) + 2 * V[0](1) * V[1](2) * X(0, 0) * x[0](0) * x[1](1) * xp[0](0) - 2 * V[0](0) * V[1](0) * X(1, 1) * x[0](1) * x[1](2) * xp[0](0) + 2 * V[0](0) * V[1](0) * X(2, 1) * x[0](1) * x[1](1) * xp[0](0) + 2 * V[0](0) * V[1](1) * X(0, 1) * x[0](1) * x[1](2) * xp[0](0) - 2 * V[0](0) * V[1](1) * X(2, 1) * x[1](0) * x[0](1) * xp[0](0) - 2 * V[0](0) * V[1](2) * X(0, 1) * x[0](1) * x[1](1) * xp[0](0) + 2 * V[0](0) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](0) - 2 * V[1](0) * V[0](1) * X(1, 1) * x[1](0) * x[0](2) * xp[0](0) + 2 * V[1](0) * V[0](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](0) + 2 * V[0](1) * V[1](1) * X(0, 1) * x[1](0) * x[0](2) * xp[0](0) - 2 * V[1](1) * V[0](2) * X(0, 1) * x[1](0) * x[0](1) * xp[0](0) + 2 * V[0](0) * V[1](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](2) - 2 * V[0](0) * V[1](2) * X(2, 0) * x[0](1) * x[1](1) * xp[0](2) - 2 * V[1](0) * V[0](1) * X(2, 0) * x[1](1) * x[0](2) * xp[0](2) + 2 * V[1](0) * V[0](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](2) + 2 * V[0](1) * V[1](1) * X(2, 0) * x[1](0) * x[0](2) * xp[0](2) - 2 * V[0](1) * V[1](2) * X(0, 0) * x[1](1) * x[0](2) * xp[0](2) + 2 * V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](1) * xp[0](2) - 2 * V[1](1) * V[0](2) * X(1, 0) * x[1](0) * x[0](2) * xp[0](2) + 2 * V[0](2) * V[1](2) * X(0, 0) * x[0](1) * x[1](1) * xp[0](2) - 2 * V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](2) + 2 * V[0](0) * V[1](1) * X(2, 1) * x[0](1) * x[1](2) * xp[0](2) - 2 * V[0](0) * V[1](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](2) - 2 * V[1](0) * V[0](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](2) + 2 * V[1](0) * V[0](2) * X(2, 1) * x[0](1) * x[1](1) * xp[0](2) - 2 * V[0](1) * V[1](1) * X(2, 1) * x[0](0) * x[1](2) * xp[0](2) + 2 * V[0](1) * V[1](2) * X(1, 1) * x[0](0) * x[1](2) * xp[0](2) + 2 * V[1](1) * V[0](2) * X(0, 1) * x[0](1) * x[1](2) * xp[0](2) - 2 * V[1](1) * V[0](2) * X(2, 1) * x[1](0) * x[0](1) * xp[0](2) - 2 * V[0](2) * V[1](2) * X(0, 1) * x[0](1) * x[1](1) * xp[0](2) + 2 * V[0](2) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](2) - 2 * V[0](0) * V[1](2) * X(1, 0) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[0](0) * V[1](2) * X(2, 0) * x[0](1) * x[1](2) * xp[0](1) + 2 * V[1](0) * V[0](1) * X(2, 0) * x[0](2) * x[1](2) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(1, 0) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[0](1) * V[1](2) * X(0, 0) * x[0](2) * x[1](2) * xp[0](1) - 2 * V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[0](1) * V[1](2) * X(2, 0) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](2) * V[1](2) * X(0, 0) * x[0](1) * x[1](2) * xp[0](1) + 2 * V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[0](2) * V[1](2) * X(1, 0) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](0) * V[1](1) * X(2, 1) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[0](0) * V[1](2) * X(1, 1) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[1](0) * V[0](2) * X(1, 1) * x[0](2) * x[1](2) * xp[0](1) - 2 * V[1](0) * V[0](2) * X(2, 1) * x[1](1) * x[0](2) * xp[0](1) - 2 * V[1](1) * V[0](2) * X(0, 1) * x[0](2) * x[1](2) * xp[0](1) + 2 * V[1](1) * V[0](2) * X(2, 1) * x[0](0) * x[1](2) * xp[0](1) + 2 * V[1](1) * V[0](2) * X(2, 1) * x[1](0) * x[0](2) * xp[0](1) + 2 * V[0](2) * V[1](2) * X(0, 1) * x[1](1) * x[0](2) * xp[0](1) - 2 * V[0](2) * V[1](2) * X(1, 1) * x[0](0) * x[1](2) * xp[0](1) - 2 * V[0](2) * V[1](2) * X(1, 1) * x[1](0) * x[0](2) * xp[0](1) - 2 * V[0](1) * V[1](1) * X(2, 0) * x[0](2) * x[1](2) * xp[0](0) + 2 * V[0](1) * V[1](2) * X(2, 0) * x[1](1) * x[0](2) * xp[0](0) + 2 * V[1](1) * V[0](2) * X(1, 0) * x[0](2) * x[1](2) * xp[0](0) - 2 * V[0](2) * V[1](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](0) + 2 * V[0](1) * V[1](1) * X(2, 1) * x[0](2) * x[1](2) * xp[0](0) - 2 * V[0](1) * V[1](2) * X(1, 1) * x[0](2) * x[1](2) * xp[0](0) - 2 * V[1](1) * V[0](2) * X(2, 1) * x[0](1) * x[1](2) * xp[0](0) + 2 * V[0](2) * V[1](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](0);
    const double c4 = V[0](0) * V[1](0) * X(1, 0) * x[1](1) * x[0](2) * xp[0](2) - V[0](0) * V[1](0) * X(2, 0) * x[0](1) * x[1](1) * xp[0](2) - V[0](0) * V[1](1) * X(1, 0) * x[1](0) * x[0](2) * xp[0](2) + V[0](0) * V[1](1) * X(2, 0) * x[1](0) * x[0](1) * xp[0](2) - V[1](0) * V[0](1) * X(0, 0) * x[1](1) * x[0](2) * xp[0](2) + V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](1) * xp[0](2) + V[1](0) * V[0](2) * X(0, 0) * x[0](1) * x[1](1) * xp[0](2) - V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](2) + V[0](1) * V[1](1) * X(0, 0) * x[1](0) * x[0](2) * xp[0](2) - V[0](1) * V[1](1) * X(2, 0) * x[0](0) * x[1](0) * xp[0](2) - V[1](1) * V[0](2) * X(0, 0) * x[1](0) * x[0](1) * xp[0](2) + V[1](1) * V[0](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](2) - V[0](0) * V[1](0) * X(1, 1) * x[0](1) * x[1](2) * xp[0](2) + V[0](0) * V[1](0) * X(2, 1) * x[0](1) * x[1](1) * xp[0](2) + V[0](0) * V[1](1) * X(0, 1) * x[0](1) * x[1](2) * xp[0](2) - V[0](0) * V[1](1) * X(2, 1) * x[1](0) * x[0](1) * xp[0](2) - V[0](0) * V[1](2) * X(0, 1) * x[0](1) * x[1](1) * xp[0](2) + V[0](0) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](2) + V[1](0) * V[0](1) * X(1, 1) * x[0](0) * x[1](2) * xp[0](2) - V[1](0) * V[0](1) * X(2, 1) * x[0](0) * x[1](1) * xp[0](2) - V[0](1) * V[1](1) * X(0, 1) * x[0](0) * x[1](2) * xp[0](2) + V[0](1) * V[1](1) * X(2, 1) * x[0](0) * x[1](0) * xp[0](2) + V[0](1) * V[1](2) * X(0, 1) * x[0](0) * x[1](1) * xp[0](2) - V[0](1) * V[1](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](2) - V[0](0) * V[1](0) * X(1, 0) * x[0](2) * x[1](2) * xp[0](1) + V[0](0) * V[1](0) * X(2, 0) * x[0](1) * x[1](2) * xp[0](1) + V[0](0) * V[1](2) * X(1, 0) * x[1](0) * x[0](2) * xp[0](1) - V[0](0) * V[1](2) * X(2, 0) * x[1](0) * x[0](1) * xp[0](1) + V[1](0) * V[0](1) * X(0, 0) * x[0](2) * x[1](2) * xp[0](1) - V[1](0) * V[0](1) * X(2, 0) * x[0](0) * x[1](2) * xp[0](1) - V[1](0) * V[0](2) * X(0, 0) * x[0](1) * x[1](2) * xp[0](1) + V[1](0) * V[0](2) * X(1, 0) * x[0](0) * x[1](2) * xp[0](1) - V[0](1) * V[1](2) * X(0, 0) * x[1](0) * x[0](2) * xp[0](1) + V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](0) * xp[0](1) + V[0](2) * V[1](2) * X(0, 0) * x[1](0) * x[0](1) * xp[0](1) - V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](0) * xp[0](1) + V[0](0) * V[1](0) * X(1, 1) * x[0](2) * x[1](2) * xp[0](1) - V[0](0) * V[1](0) * X(2, 1) * x[1](1) * x[0](2) * xp[0](1) - V[0](0) * V[1](1) * X(0, 1) * x[0](2) * x[1](2) * xp[0](1) + V[0](0) * V[1](1) * X(2, 1) * x[1](0) * x[0](2) * xp[0](1) + V[0](0) * V[1](2) * X(0, 1) * x[1](1) * x[0](2) * xp[0](1) - V[0](0) * V[1](2) * X(1, 1) * x[1](0) * x[0](2) * xp[0](1) - V[1](0) * V[0](2) * X(1, 1) * x[0](0) * x[1](2) * xp[0](1) + V[1](0) * V[0](2) * X(2, 1) * x[0](0) * x[1](1) * xp[0](1) + V[1](1) * V[0](2) * X(0, 1) * x[0](0) * x[1](2) * xp[0](1) - V[1](1) * V[0](2) * X(2, 1) * x[0](0) * x[1](0) * xp[0](1) - V[0](2) * V[1](2) * X(0, 1) * x[0](0) * x[1](1) * xp[0](1) + V[0](2) * V[1](2) * X(1, 1) * x[0](0) * x[1](0) * xp[0](1) + V[0](0) * V[1](1) * X(1, 0) * x[0](2) * x[1](2) * xp[0](0) - V[0](0) * V[1](1) * X(2, 0) * x[0](1) * x[1](2) * xp[0](0) - V[0](0) * V[1](2) * X(1, 0) * x[1](1) * x[0](2) * xp[0](0) + V[0](0) * V[1](2) * X(2, 0) * x[0](1) * x[1](1) * xp[0](0) - V[0](1) * V[1](1) * X(0, 0) * x[0](2) * x[1](2) * xp[0](0) + V[0](1) * V[1](1) * X(2, 0) * x[0](0) * x[1](2) * xp[0](0) + V[0](1) * V[1](2) * X(0, 0) * x[1](1) * x[0](2) * xp[0](0) - V[0](1) * V[1](2) * X(2, 0) * x[0](0) * x[1](1) * xp[0](0) + V[1](1) * V[0](2) * X(0, 0) * x[0](1) * x[1](2) * xp[0](0) - V[1](1) * V[0](2) * X(1, 0) * x[0](0) * x[1](2) * xp[0](0) - V[0](2) * V[1](2) * X(0, 0) * x[0](1) * x[1](1) * xp[0](0) + V[0](2) * V[1](2) * X(1, 0) * x[0](0) * x[1](1) * xp[0](0) - V[1](0) * V[0](1) * X(1, 1) * x[0](2) * x[1](2) * xp[0](0) + V[1](0) * V[0](1) * X(2, 1) * x[1](1) * x[0](2) * xp[0](0) + V[1](0) * V[0](2) * X(1, 1) * x[0](1) * x[1](2) * xp[0](0) - V[1](0) * V[0](2) * X(2, 1) * x[0](1) * x[1](1) * xp[0](0) + V[0](1) * V[1](1) * X(0, 1) * x[0](2) * x[1](2) * xp[0](0) - V[0](1) * V[1](1) * X(2, 1) * x[1](0) * x[0](2) * xp[0](0) - V[0](1) * V[1](2) * X(0, 1) * x[1](1) * x[0](2) * xp[0](0) + V[0](1) * V[1](2) * X(1, 1) * x[1](0) * x[0](2) * xp[0](0) - V[1](1) * V[0](2) * X(0, 1) * x[0](1) * x[1](2) * xp[0](0) + V[1](1) * V[0](2) * X(2, 1) * x[1](0) * x[0](1) * xp[0](0) + V[0](2) * V[1](2) * X(0, 1) * x[0](1) * x[1](1) * xp[0](0) - V[0](2) * V[1](2) * X(1, 1) * x[1](0) * x[0](1) * xp[0](0);

    double qq[4];
    const double inv_c0 = 1.0 / c0;
    const int sols = univariate::solve_quartic_real(c1 * inv_c0, c2 * inv_c0, c3 * inv_c0, c4 * inv_c0, qq);

    output->clear();
    for (int i = 0; i < sols; ++i) {

        CameraPose pose;
        const double q = qq[i];
        const double q2 = q * q;
        const double inv_norm = 1.0 / (1 + q2);
        const double cq = (1 - q2) * inv_norm;
        const double sq = 2 * q * inv_norm;

        pose.R.setIdentity();
        pose.R(0, 0) = cq;
        pose.R(0, 2) = sq;
        pose.R(2, 0) = -sq;
        pose.R(2, 2) = cq;

        Eigen::Vector3d a = x[0].cross(pose.R * V[0]);
        Eigen::Vector3d b = pose.R * X.col(0);

        double alpha = -a.dot(b) / a.dot(xp[0]);
        pose.t = alpha * xp[0] - pose.R * Xp[0];
        output->push_back(pose);
    }

    return sols;
}
