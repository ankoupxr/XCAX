#include "XStepRW.h"

TopoDS_Shape XStepRW::readFiles(const std::string filepath)
{

	//STEPControl_Reader reader_Step;

	auto file = filepath.data();

	//��ȡSTEP�ļ�
	STEPControl_Reader aReader_Step;
	aReader_Step.ReadFile(file);
	//����ļ�����״̬
	aReader_Step.PrintCheckLoad(Standard_False, IFSelect_ItemsByEntity);
	//����step�ļ�
	Standard_Integer NbRoots = aReader_Step.NbRootsForTransfer();// ��ȡ��ת�Ƹ�������
	Standard_Integer num = aReader_Step.TransferRoots();//�������п�ת���ĸ���������//�ɹ�����Ĵ���
	//��ȡ��TopoDS_Shape�ṹ��
	TopoDS_Shape aShape = aReader_Step.OneShape();

	return aShape;
}