/**
 * @param {Function} fn
 * @return {Object}
 */
// const _ = require('lodash');

Array.prototype.groupBy = function(fn) {
//   return this.reduce((grouped,item)=>{
//      const key=fn(item);
//      if(!grouped[key]){
// grouped[key]=[];
//      }
// grouped[key].push(item)
// return grouped;
    
//    },{})
return _.groupBy(this,fn);
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */