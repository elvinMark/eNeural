function eMatrix(rows,cols){
    this.data = [];
    this.rows = rows;
    this.cols = cols;
    for(var i = 0;i<this.rows;i++)
	this.data.push(new Array(this.cols));

    this.random = function(){
	for(var i = 0;i<this.rows;i++)
	    for(var j = 0;j<this.cols;j++)
		this.data[i][j] = Math.random(); 
    };

    this.zeros = function(){
	for(var i = 0;i<this.rows;i++)
	    for(var j = 0;j<this.cols;j++)
		this.data[i][j] = 0;
    };

    this.ones = function(){
	for(var i = 0;i<this.rows;i++)
	    for(var j = 0;j<this.cols;j++)
		this.data[i][j] = 1;
    };

    this.plus = function(M){
	var out = new eMatrix(this.rows,this.cols);
	if(M.rows == 1 && M.cols == this.cols){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] + M.data[0][j];
	}
	else if(M.cols == 1 && M.rows == this.rows){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] + M.data[i][0];
	}
	else if(M.cols == this.cols && M.rows == this.rows){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] + M.data[i][j];
	}
	return out;
    }

    this.minus = function(M){
	var out = new eMatrix(this.rows,this.cols);
	if(M.rows == 1 && M.cols == this.cols){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] - M.data[0][j];
	}
	else if(M.cols == 1 && M.rows == this.rows){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] - M.data[i][0];
	}
	else if(M.cols == this.cols && M.rows == this.rows){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] - M.data[i][j];
	}
	return out;
    }

    this.times = function(M){
	var out = new eMatrix(this.rows,this.cols);
	if(M.rows == 1 && M.cols == this.cols){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] * M.data[0][j];
	}
	else if(M.cols == 1 && M.rows == this.rows){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] * M.data[i][0];
	}
	else if(M.cols == this.cols && M.rows == this.rows){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] * M.data[i][j];
	}
	return out;
    }

    this.divides = function(M){
	var out = new eMatrix(this.rows,this.cols);
	if(M.rows == 1 && M.cols == this.cols){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] / M.data[0][j];
	}
	else if(M.cols == 1 && M.rows == this.rows){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] / M.data[i][0];
	}
	else if(M.cols == this.cols && M.rows == this.rows){
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][j] = this.data[i][j] / M.data[i][j];
	}
	return out;
    }

    this.scale = function(num){
	var out = new eMatrix(this.rows,this.cols);
	for(var i = 0;i<this.rows;i++)
	    for(var j = 0;j<this.cols;j++)
		out.data[i][j] = this.data[i][j]*num;
	return out;
    }

    this.dot = function(M){
	var out = new eMatrix(this.rows,M.cols);
	var s;
	for(var i = 0;i<this.rows;i++){
	    for(var j = 0;j<M.cols;j++){
		s = 0;
		for(var k = 0;k<this.cols;k++)
		    s += this.data[i][k] * M.data[k][j];
		out.data[i][j] = s;
	    }
	}
	return out;
    }

    this.applyFunc = function(funf){
	var out = new eMatrix(this.rows,this.cols);
	for(var i = 0;i<this.rows;i++)
	    for(var j = 0;j<this.cols;j++)
		out.data[i][j] = funf(this.data[i][j]);
	return out;
    }

    this.transpose = function(){
	var out = new eMatrix(this.cols,this.rows);	
	for(var i = 0;i<this.rows;i++)
	    for(var j = 0;j<this.cols;j++)
		out.data[j][i] = this.data[i][j];
	return out;
    }

    this.sum = function(axis){
	var out;
	if(axis == 0){
	    out = new eMatrix(1,this.cols);
	    out.zeros();
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[0][j] += this.data[i][j];
	}

	else if(axis==1){
	    out = new eMatrix(this.rows,1);
	    out.zeros();
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out.data[i][0] += this.data[i][j];
	}
	else{
	    out = 0;
	    for(var i = 0;i<this.rows;i++)
		for(var j = 0;j<this.cols;j++)
		    out += this.data[i][j];
	}
	return out;
    }
    
    this.toString = function(){
	var s = "";
	
	for(var i = 0;i<this.rows;i++){
	    for(var j = 0;j<this.cols;j++)
		s += this.data[i][j] + " ";
	    s += "\n";
	}
    return s;
    }
    
}

function eLinear(num_in,num_out){
    this.W = new eMatrix(num_in,num_out);
    this.b = new eMatrix(1,num_out);

    this.W.random();
    this.b.random();
    
    this.tmp_i = null;
    this.tmp_o = null;
    this.tmp_e = null;
    
    this.forward = function(inp){
	this.tmp_i = inp;
	this.tmp_o = inp.dot(this.W).plus(this.b);
	return this.tmp_o;
    };

    this.backward = function(err){
	this.tmp_e = err;
	return err.dot(this.W.transpose());
    };

    this.update = function(learning_rate){
	var deltaW,deltab;
	deltaW = this.tmp_i.transpose().dot(this.tmp_e);
	deltab = this.tmp_e.sum(0);
	this.W = this.W.minus(deltaW.scale(learning_rate));
	this.b = this.b.minus(deltab.scale(learning_rate));
    };
}

function eSigmoid(){
    this.tmp_i = null;
    this.tmp_o = null;
    this.tmp_e = null;
    
    this.forward = function(inp){
	this.tmp_i = inp;
	this.tmp_o = inp.applyFunc((x)=>1/(1 + Math.exp(-x)));
	return this.tmp_o;
    };
    
    this.backward = function(err){
	this.tmp_e = err;
	return this.tmp_o.applyFunc((x)=>x*(1-x)).times(err);
    };

    this.update = function(learning_rate){

    };
}

function eTanh(){
    this.tmp_i = null;
    this.tmp_o = null;
    this.tmp_e = null;
    
    this.forward = function(inp){
	this.tmp_i = inp;
	this.tmp_o = inp.applyFunc((x)=>(1 - Math.exp(-x))/(1 + Math.exp(-x)));
	return this.tmp_o;
    };
    
    this.backward = function(err){
	this.tmp_e = err;
	return this.tmp_o.applyFunc((x)=>(1-x*x)/2.0).times(err);
    };

    this.update = function(learning_rate){

    };
}

function eReLU(){
    this.tmp_i = null;
    this.tmp_o = null;
    this.tmp_e = null;
    
    this.forward = function(inp){
	this.tmp_i = inp;
	this.tmp_o = inp.applyFunc((x)=>x>0?x:0.001*x);
	return this.tmp_o;
    };
    
    this.backward = function(err){
	this.tmp_e = err;
	return this.tmp_o.applyFunc((x)=>x>0?1:0.001).times(err);
    };

    this.update = function(learning_rate){

    };
}

function eSoftmax(){
    this.tmp_i = null;
    this.tmp_o = null;
    this.tmp_e = null;
    
    this.forward = function(inp){
	var tmp;
	this.tmp_i = inp;
	tmp = inp.applyFunc(Math.exp);
	this.tmp_o = tmp.divides(tmp.sum(1));
	return this.tmp_o;
    };
    
    this.backward = function(err){
	var tmp;
	this.tmp_e = err;
	tmp = this.tmp_o.times(err)
	return tmp.minus(this.tmp_o.times(tmp.sum(1)));
    };

    this.update = function(learning_rate){

    };    
}

function eMeanSquareLoss(){
    this.err = null;
    
    this.calculate_loss = function(out,target){
	this.err = out.minus(target);
	return this.err.times(this.err).sum(2);
    };
    
    this.grad_loss = function(){
	return this.err;
    };
}


function eCrossEntropyLoss(){
    this.tmp_t = null;
    this.tmp_o = null;
    this.calculate_loss = function(out,target){
	this.tmp_t = target;
	this.tmp_o = out;
	return target.times(out.applyFunc(Math.log)).sum(2)*-1;
    };
    
    this.grad_loss = function(){
	return this.tmp_t.divides(this.tmp_o).scale(-1);
    };
}

function eSequential(){
    this.layers = [];

    this.addLayer = function(layer){
	this.layers.push(layer);
    };

    this.forward = function(inp){
	var tmp = inp;
	for(var i in this.layers)
	    tmp = this.layers[i].forward(tmp);
	return tmp;
    };

    this.backward = function(err){
	var tmp = err;
	for(var i = this.layers.length - 1;i>=0;i--)
	    tmp = this.layers[i].backward(tmp);
	return tmp;
    };

    this.update = function(learning_rate){
	for(var i in this.layers)
	    this.layers[i].update(learning_rate);
    };

    this.train = function(inp,target,loss,learning_rate,epochs){
	var tmp,err,curr_loss;
	for(var i = 0;i<epochs;i++){
	    tmp = this.forward(inp);
	    curr_loss = loss.calculate_loss(tmp,target);
	    console.log(curr_loss);
	    this.backward(loss.grad_loss());
	    this.update(learning_rate);
	}
    };
}

var s = new eSequential();
var inp,target;

inp = new eMatrix(4,2);
target = new eMatrix(4,2);

inp.data = [[0,0],[1,0],[0,1],[1,1]];
target.data = [[1,0],[0,1],[0,1],[1,0]];

s.addLayer(new eLinear(2,3));
s.addLayer(new eSigmoid());
s.addLayer(new eLinear(3,5));
s.addLayer(new eReLU());
s.addLayer(new eLinear(5,2));
s.addLayer(new eReLU());
s.addLayer(new eSoftmax());
s.train(inp,target,new eCrossEntropyLoss(),0.1,2000);
console.log(s.forward(inp).toString());
