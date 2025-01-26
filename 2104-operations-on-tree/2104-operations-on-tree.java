class LockingTree {
    // array for lock, hashmaps: parent and child
    int[] lock;
    Map<Integer, Integer> parent;
    Map<Integer, List<Integer>> child;

    public LockingTree(int[] parent) {
        this.lock = new int[parent.length];
        Arrays.fill(this.lock, -1);
        this.parent = new HashMap<>();
        this.child = new HashMap<>();
        for (int i = 0; i < parent.length; i++) {
            this.parent.put(i, parent[i]);
            this.child.putIfAbsent(parent[i], new ArrayList<>());
            this.child.get(parent[i]).add(i);
        }
        // System.out.println(this.parent);
        // System.out.println(this.child);
    }

    public boolean lock(int num, int user) {
        if (this.lock[num] == -1) {
            this.lock[num] = user;
            return true;
        }
        return false;
    }

    public boolean unlock(int num, int user) {
        if (this.lock[num] == user) {
            this.lock[num] = -1;
            return true;
        }
        return false;
    }

    public boolean upgrade(int num, int user) {
        int cur = num;
        while (this.parent.containsKey(cur)) {
            if (cur != -1 && this.lock[cur] != -1)
                return false;
            cur = this.parent.get(cur);
        }
        List<Integer> lock_child = new ArrayList<>();
        dfs(num, lock_child);
        /*
         * Queue<Integer> queue = new LinkedList<>();
         * queue.offer(num);
         * while (!queue.isEmpty()) {
         * int sz = queue.size();
         * while (sz-- > 0) {
         * int next = queue.poll();
         * if (this.lock[next] != -1)
         * lock_child.add(next);
         * if (this.child.containsKey(next)) {
         * for (int val : this.child.get(next))
         * queue.offer(val);
         * }
         * }
         * // System.out.println(queue);
         * }
         */
        if (lock_child.size() > 0) {
            this.lock[num] = user;
            for (int val : lock_child)
                this.lock[val] = -1;
            return true;
        }
        return false;
    }

    void dfs(int num, List<Integer> lock_child) {
        for (int val : this.child.getOrDefault(num, List.of())) {
            if (this.lock[val] != -1)
                lock_child.add(val);
            dfs(val, lock_child);
        }
    }
}
