window.onload = function(){
				
					//基于准备好的dom 初始化
			var myChart = echarts.init(document.getElementById('main'));
			var option = {
				title:{
					text:'工资'
				},
	
               backgroundColor: 'white',
				tooltip:{},
				legend:{
					data:['工资']
				},
				
				xAxis:{
					data:["高工","王工","戴工","谢工","吉工","刘工"]
				},
				yAxis:{},
				series:[{
					
					name:'工资',
					type:'bar',
					data:[30000,10000,15000,1000,8000,9000]
				}]
		};
			
		myChart.setOption(option)
		
		/*
		 * expandSty 展开的div
		 */
		function BtnShrink(shrinkSty){
			
			shrinkSty.style.height = 10+'px';
			
		}
		/*
		 *  btnFlag = 0代表展开
		 *  btnFlag = 1代表伸缩
		 */
		var btnFlag = 0;
		var btnShrink = document.getElementsByClassName("buttonShrink");
		var shrinkArr = document.getElementsByClassName("shrink");
		//console.log(shrinkArr.length);
		 for(var i = 0; i < btnShrink.length;i++ )
		 {
		 	btnShrink[i].onclick = function (){
		 		
		 		if(btnFlag == 0)
		 		{
		 			this.nextElementSibling.style.height = 10+'px'; 
		 			btnFlag = 1;
		 			//alert(this.nextElementSibling.children.tagName);
		 			this.nextElementSibling.children[0].style.display = "none";
		 			
		 		}
		 		
		 		else
		 		{
		 			this.nextElementSibling.style.height = 200+'px';
		 			btnFlag = 0;
		 			this.nextElementSibling.children[0].style.display = "block";
		 		}
		 		
		 	}
		 }
		
		//操作表格,给每个表格都写一个id??
		var ener = document.getElementById("ener");
		ener.innerHTML = "60";
		
}
			