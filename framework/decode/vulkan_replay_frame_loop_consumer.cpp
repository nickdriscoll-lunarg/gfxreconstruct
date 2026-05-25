/*
** Copyright (c) 2026 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "decode/vulkan_replay_frame_loop_consumer.h"

#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "generated/generated_vulkan_replay_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

#define CHECK_VK_RESULT(_res_, _func_)                                        \
    {                                                                         \
        VkResult _RES = (_res_);                                              \
        if (_RES != VK_SUCCESS)                                               \
        {                                                                     \
            GFXRECON_LOG_ERROR("[%s:%u] synthetic call to %s failed with %s", \
                               __FILE__,                                      \
                               __LINE__,                                      \
                               _func_,                                        \
                               util::ToString(_RES).c_str());                 \
            std::exit(-1);                                                    \
        }                                                                     \
    }

void VulkanReplayFrameLoopConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*                    pInstance)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the instance has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateInstance(call_info, returnValue, pCreateInfo, pAllocator, pInstance);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                                        call_info,
    VkResult                                                  returnValue,
    format::HandleId                                          instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                       pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                                       call_info,
    VkResult                                                 returnValue,
    format::HandleId                                         instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                      pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                        pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }
    VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                        pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateMetalSurfaceEXT(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                                            call_info,
    VkResult                                                      returnValue,
    format::HandleId                                              instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*          pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                           pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                                            call_info,
    VkResult                                                      returnValue,
    format::HandleId                                              instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*          pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                           pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateDirectFBSurfaceEXT(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                                          call_info,
    VkResult                                                    returnValue,
    format::HandleId                                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                         pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateScreenSurfaceQNX(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the surface has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
        call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*                      pDevice)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the device has already been created during the first iteration of the frame.
        return;
    }
    VulkanReplayConsumer::Process_vkCreateDevice(
        call_info, returnValue, physicalDevice, pCreateInfo, pAllocator, pDevice);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the swapchain has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::Process_vkCreateSwapchainKHR(
        call_info, returnValue, device, pCreateInfo, pAllocator, pSwapchain);
}

void VulkanReplayFrameLoopConsumer::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    if (frame_loop_info_.IsRepetition())
    {
        // When repeating a frame, the hardware buffer has already been created during the first iteration of the frame.
        return;
    }

    VulkanReplayConsumer::ProcessCreateHardwareBufferCommand(
        device_id, memory_id, buffer_id, format, width, height, stride, usage, layers, plane_info);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                                     call_info,
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkCommandPool>*                   pCommandPool)
{
    if (frame_loop_info_.IsRepetition())
    {
        // Don't repeatedly recreate the command pool during the looping frame
        return;
    }

    // Set VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT in order to prevent validation
    // error regarding implicitly resetting the command buffer
    VkCommandPoolCreateInfo* create_info = pCreateInfo->GetPointer();
    create_info->flags |= VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

    VulkanReplayConsumer::Process_vkCreateCommandPool(
        call_info, returnValue, device, pCreateInfo, pAllocator, pCommandPool);
}

void VulkanReplayFrameLoopConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    if (!GetLoadingTrimmedState())
    {
        if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
        {
            // On first iteration of looping frame, record command buffers that are explicitly begun
            VkCommandBufferBeginInfo* info = pBeginInfo->GetPointer();
            if (info->pInheritanceInfo == nullptr)
            {
                GFXRECON_LOG_INFO("Just observed vkBeginCommandBuffer(%" PRIu64 ")", commandBuffer);
                begun_command_buffers_.insert(commandBuffer);
            }
        }
    }

    VulkanReplayConsumer::Process_vkBeginCommandBuffer(
        call_info,
        returnValue,
        commandBuffer,
        pBeginInfo
    );
}

void VulkanReplayFrameLoopConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                     pDescriptorSets)
{
    if (frame_loop_info_.IsRepetition())
    {
        // Only allocate descriptor sets during the first iteration of the looping frame
        return;
    }

    VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
        call_info, returnValue, device, pAllocateInfo, pDescriptorSets);
}

void VulkanReplayFrameLoopConsumer::Process_vkWaitForFences(const ApiCallInfo&             call_info,
                                                            VkResult                       returnValue,
                                                            format::HandleId               device,
                                                            uint32_t                       fenceCount,
                                                            HandlePointerDecoder<VkFence>* pFences,
                                                            VkBool32                       waitAll,
                                                            uint64_t                       timeout)
{
    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        for (int i = 0; i < fenceCount; ++i)
        {
            if (!per_device_fence_tracking_.contains(device))
            {
                per_device_fence_tracking_[device] = {};
            }
            FenceTracking& t = per_device_fence_tracking_[device];

            format::HandleId fence = pFences->GetPointer()[i];
            if (t.waited_upon_fences_.contains(fence))
            {
                t.waited_upon_fences_[fence] += 1;
            }
            else
            {
                t.waited_upon_fences_[fence] = 1;
            }
            GFXRECON_LOG_DEBUG("VkFence with handle \"%" PRIu64 "\" has been waited on %" PRIu32 " times.",
                               fence,
                               t.waited_upon_fences_[fence]);
        }
    }

    VulkanReplayConsumer::Process_vkWaitForFences(
        call_info, returnValue, device, fenceCount, pFences, waitAll, timeout);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                                                          VkResult                                    returnValue,
                                                          format::HandleId                            queue,
                                                          uint32_t                                    submitCount,
                                                          StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                          format::HandleId                            fence)
{
    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        // Collect fences submitted during the looping frame
        VulkanFenceInfo* fence_info = GetObjectInfoTable().GetVkFenceInfo(fence);
        if (fence_info != nullptr)
        {
            format::HandleId device = GetObjectInfoTable().GetVkQueueInfo(queue)->parent_id;
            if (!per_device_fence_tracking_.contains(device))
            {
                per_device_fence_tracking_[device] = {};
            }
            FenceTracking& t = per_device_fence_tracking_[device];

            if (t.signaled_fences_.contains(fence))
            {
                t.signaled_fences_[fence] += 1;
            }
            else
            {
                t.signaled_fences_[fence] = 1;
            }
            t.signaled_fences_[fence];
            GFXRECON_LOG_DEBUG("VkFence with handle \"%" PRIu64 "\" has been signaled %" PRIu32 " times.",
                               fence,
                               t.signaled_fences_[fence]);
        }

        // Collect command buffers submitted during the looping frame
        MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
        for (int submit_idx = 0; submit_idx < submitCount; ++submit_idx)
        {
            Decoded_VkSubmitInfo meta_ptr = pSubmits->GetMetaStructPointer()[submit_idx];
            const format::HandleId* cbs = meta_ptr.pCommandBuffers.GetPointer();
            for (int i = 0; i < meta_ptr.pCommandBuffers.GetLength(); ++i)
            {
                GFXRECON_LOG_INFO("Just observed queue submission of (%" PRIu64 ")", cbs[i]);
                submitted_command_buffers_.insert(cbs[i]);
            }
        }
    }

    VulkanReplayConsumer::Process_vkQueueSubmit(call_info, returnValue, queue, submitCount, pSubmits, fence);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2(const ApiCallInfo&                           call_info,
                                                           VkResult                                     returnValue,
                                                           format::HandleId                             queue,
                                                           uint32_t                                     submitCount,
                                                           StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                           format::HandleId                             fence)
{
    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        
        // Collect command buffers submitted during the looping frame
        MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
        for (int submit_idx = 0; submit_idx < submitCount; ++submit_idx)
        {
            Decoded_VkSubmitInfo2 meta_ptr = pSubmits->GetMetaStructPointer()[submit_idx];
            MapStructArrayHandles(meta_ptr.pCommandBufferInfos->GetMetaStructPointer(), meta_ptr.pCommandBufferInfos->GetLength(), GetObjectInfoTable());
            for (int i = 0; i < meta_ptr.pCommandBufferInfos->GetLength(); ++i)
            {
                Decoded_VkCommandBufferSubmitInfo cbinfo = meta_ptr.pCommandBufferInfos->GetMetaStructPointer()[i];
                submitted_command_buffers_.insert(cbinfo.commandBuffer);
            }
        }
    }

    VulkanReplayConsumer::Process_vkQueueSubmit2(
        call_info,
        returnValue,
        queue,
        submitCount,
        pSubmits,
        fence
    );
}

void VulkanReplayFrameLoopConsumer::FixupDeviceFences(format::HandleId device, format::HandleId queue)
{
    // Get fence tracking info associated with this VkDevice
    if (!per_device_fence_tracking_.contains(device))
    {
        // No need to fixup fences if there weren't any
        return;
    }
    FenceTracking& t = per_device_fence_tracking_[device];

    VulkanObjectInfoTable&             table        = GetObjectInfoTable();
    VkDevice                           vk_device    = table.GetVkDeviceInfo(device)->handle;
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(vk_device);

    // Gather fences that need to be synthetically waited on
    std::vector<VkFence> manual_wait_fences;
    manual_wait_fences.reserve(t.signaled_fences_.size());
    for (auto [fence_id, signal_count] : t.signaled_fences_)
    {
        uint32_t wait_count = 0;
        if (t.waited_upon_fences_.contains(fence_id))
        {
            wait_count = t.waited_upon_fences_[fence_id];
        }

        // Manually wait on the fence if it's signaled more times than it is waited upon
        if (signal_count > wait_count)
        {
            GFXRECON_LOG_DEBUG("Will synthetically wait on fence %" PRIu64, fence_id);
            VulkanFenceInfo* fence_info = table.GetVkFenceInfo(fence_id);
            manual_wait_fences.push_back(fence_info->handle);
        }
    }

    // Gather fences that need to be synthetically signaled
    std::vector<VkFence> manual_signal_fences;
    manual_signal_fences.reserve(t.signaled_fences_.size());
    for (auto [fence_id, wait_count] : t.waited_upon_fences_)
    {
        uint32_t signal_count = 0;
        if (t.signaled_fences_.contains(fence_id))
        {
            signal_count = t.signaled_fences_[fence_id];
        }

        // Manually signal fence if it's waited on more times than it is signaled
        if (wait_count > signal_count)
        {
            GFXRECON_LOG_DEBUG("Will synthetically signal fence %" PRIu64, fence_id);
            VulkanFenceInfo* fence_info = table.GetVkFenceInfo(fence_id);
            manual_signal_fences.push_back(fence_info->handle);
        }
    }

    VkResult result;

    if (manual_wait_fences.size() > 0)
    {
        GFXRECON_LOG_DEBUG("Synthetically waiting on fences...");
        result = device_table->WaitForFences(vk_device,
                                             manual_wait_fences.size(),
                                             manual_wait_fences.data(),
                                             VK_TRUE,
                                             std::numeric_limits<uint64_t>::max());
        CHECK_VK_RESULT(result, "vkWaitForFences");

        GFXRECON_LOG_DEBUG("Resetting synthetically waited on fences...");
        result = device_table->ResetFences(vk_device, manual_wait_fences.size(), manual_wait_fences.data());
        CHECK_VK_RESULT(result, "vkResetFences");
    }

    if (manual_signal_fences.size() > 0)
    {
        // Fences may have been waited on but not reset, so we reset the fences we're going
        // to manually signal here just in case.
        result = device_table->ResetFences(vk_device, manual_signal_fences.size(), manual_signal_fences.data());
        CHECK_VK_RESULT(result, "vkResetFences");

        GFXRECON_LOG_DEBUG("Synthetically signaling fences...");
        for (VkFence fence : manual_signal_fences)
        {
            VulkanQueueInfo* queue_info = table.GetVkQueueInfo(queue);
            result                      = device_table->QueueSubmit(queue_info->handle, 0, nullptr, fence);
            CHECK_VK_RESULT(result, "vkDeviceWaitIdle");
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                              call_info,
    VkResult                                        returnValue,
    format::HandleId                                queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    VulkanReplayConsumer::Process_vkQueuePresentKHR(call_info, returnValue, queue, pPresentInfo);

    // Get device
    CommonObjectInfoTable& table      = GetObjectInfoTable();
    VulkanQueueInfo*       queue_info = table.GetVkQueueInfo(queue);
    VkDevice               device     = queue_info->parent;
    GFXRECON_ASSERT(device);
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
    GFXRECON_ASSERT(device_table);

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        GFXRECON_LOG_INFO("Computing list of unbegun command buffers...");

        // Determine final list of command buffers that need synthetic vkBeginCommandBuffer()
        std::vector<format::HandleId> handles;

        std::vector<format::HandleId> submitted_cbs;
        submitted_cbs.resize(submitted_command_buffers_.size());
        std::copy(submitted_command_buffers_.begin(), submitted_command_buffers_.end(), submitted_cbs.begin());
        std::vector<format::HandleId> begun_cbs;
        begun_cbs.resize(begun_command_buffers_.size());
        std::copy(begun_command_buffers_.begin(), begun_command_buffers_.end(), begun_cbs.begin());

        std::sort(submitted_cbs.begin(), submitted_cbs.end());
        std::sort(begun_cbs.begin(), begun_cbs.end());

        GFXRECON_LOG_INFO("submitted_command_buffers_:");
        for (format::HandleId handle : submitted_cbs)
        {
            GFXRECON_LOG_INFO("handle %" PRIu64, handle);
        }
        GFXRECON_LOG_INFO("begun_command_buffers_:");
        for (format::HandleId handle : begun_cbs)
        {
            GFXRECON_LOG_INFO("handle %" PRIu64, handle);
        }

        std::set_difference(
            submitted_cbs.begin(),
            submitted_cbs.end(),
            begun_cbs.begin(),
            begun_cbs.end(),
            handles.begin()
        );
        GFXRECON_LOG_INFO("handle count: %i", handles.size());
        GFXRECON_LOG_INFO("handles:");
        for (format::HandleId handle : handles)
        {
            GFXRECON_LOG_INFO("handle %" PRIu64, handle);
        }

        for (format::HandleId handle : handles)
        {
            VulkanCommandBufferInfo* cb_info = table.GetVkCommandBufferInfo(handle);
            if (cb_info == nullptr)
            {
                GFXRECON_LOG_ERROR("THIS SHOULDN'T BE POSSIBLE BRO!");
            }
            GFXRECON_LOG_INFO("unbegun command buffer with replay-time handle 0x%" PRIx64 "...", cb_info->handle);
            unbegun_command_buffers_.push_back(cb_info->handle);
        }
    }

    if (frame_loop_info_.IsLooping())
    {
        VkResult result;

        GFXRECON_LOG_DEBUG("Waiting for device to idle...");
        result = device_table->DeviceWaitIdle(device);
        CHECK_VK_RESULT(result, "vkDeviceWaitIdle");

        FixupDeviceFences(queue_info->parent_id, queue);

        // Synthetically begin command buffers that need it
        for (VkCommandBuffer cb : unbegun_command_buffers_)
        {
            VkCommandBufferBeginInfo info = {};
            info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

            GFXRECON_LOG_INFO("Beginning cb with replay-time handle 0x%" PRIx64, cb);
            device_table->BeginCommandBuffer(cb, &info);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
