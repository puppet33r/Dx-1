#include <windows.h>
#include <DirectXMath.h>
#include <iostream>

std::ostream& operator << (std::ostream &os, DirectX::FXMVECTOR v)
{
	DirectX::XMFLOAT3 dest;
	DirectX::XMStoreFloat3(&dest, v);
	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main()
{
	std::cout.setf(std::ios_base::boolalpha);
	if (!DirectX::XMVerifyCPUSupport()) { std::cout << "DirectX math not supported" << std::endl; return 0; }
	DirectX::XMVECTOR p = DirectX::XMVectorZero();
	DirectX::XMVECTOR q = DirectX::XMVectorSplatOne();
	DirectX::XMVECTOR u = DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	DirectX::XMVECTOR v = DirectX::XMVectorReplicate(-2.0f);
	DirectX::XMVECTOR w = DirectX::XMVectorSplatZ(u);

	std::cout << "p = " << p << std::endl;
	std::cout << "q = " << q << std::endl;
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "w = " << w << std::endl;
	
	return 0;
}