var RandomizedCollection = function() {
    this.map = new Map();   // val -> list of indices in arr
    this.arr = [];          // stores all elements including duplicates
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedCollection.prototype.insert = function(val) {
    if (!this.map.has(val)) {
        this.map.set(val, [this.arr.length]);
        this.arr.push(val);
        return true;
    }
    const curr_arr = this.map.get(val);
    curr_arr.push(this.arr.length);
    this.map.set(val, curr_arr);
    this.arr.push(val);
    return false;
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedCollection.prototype.remove = function(val) {
    if (!this.map.has(val)) return false;

    const val_indices = this.map.get(val);
    const remove_idx = val_indices.pop();                 // index to remove
    const last_val = this.arr[this.arr.length - 1];       // last element

    this.arr[remove_idx] = last_val;                      // swap positions

    const last_val_indices = this.map.get(last_val);
    last_val_indices[last_val_indices.indexOf(this.arr.length - 1)] = remove_idx;

    if (val_indices.length === 0) this.map.delete(val);

    this.arr.pop();
    return true;
};

/**
 * @return {number}
 */
RandomizedCollection.prototype.getRandom = function() {
    return this.arr[Math.floor(Math.random() * this.arr.length)];
};