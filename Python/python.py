class Solution:
    def connect(self, root):
        if not root:
            return None

        q = [root]
        front = 0

        while front < len(q):
            size = len(q) - front
            prev = None

            for _ in range(size):
                node = q[front]
                front += 1

                if prev:
                    prev.next = node

                prev = node

                if node.left:
                    q.append(node.left)

                if node.right:
                    q.append(node.right)

            prev.next = None

        return root