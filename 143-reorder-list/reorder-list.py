class Solution:
    def reorderList(self, head):
        if not head or not head.next:
            return
        
        # Step 1: find middle
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        # Step 2: reverse second half
        prev, curr = None, slow.next
        slow.next = None  # split
        
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
        # Step 3: merge
        first, second = head, prev
        
        while second:
            temp1 = first.next
            temp2 = second.next
            
            first.next = second
            second.next = temp1
            
            first = temp1
            second = temp2