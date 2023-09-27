#include "XStepRW.h"

TopoDS_Shape XStepRW::readFiles(const std::string filepath)
{

	//STEPControl_Reader reader_Step;

	auto file = filepath.data();

	//读取STEP文件
	STEPControl_Reader aReader_Step;
	aReader_Step.ReadFile(file);
	//检查文件加载状态
	aReader_Step.PrintCheckLoad(Standard_False, IFSelect_ItemsByEntity);
	//加载step文件
	Standard_Integer NbRoots = aReader_Step.NbRootsForTransfer();// 获取可转移根的数量
	Standard_Integer num = aReader_Step.TransferRoots();//翻译所有可转换的根，并返回//成功翻译的次数
	//读取到TopoDS_Shape结构中
	TopoDS_Shape aShape = aReader_Step.OneShape();

	return aShape;
}