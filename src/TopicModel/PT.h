#pragma once
#include "LDA.h"

namespace tomoto
{
	template<TermWeight _tw>
	struct DocumentPT : public DocumentLDA<_tw>
	{
		using BaseDocument = DocumentLDA<_tw>;
		using DocumentLDA<_tw>::DocumentLDA;
		using WeightType = typename DocumentLDA<_tw>::WeightType;
		
		uint64_t pseudoDoc = 0;

		DEFINE_SERIALIZER_AFTER_BASE_WITH_VERSION(BaseDocument, 0, pseudoDoc);
		DEFINE_TAGGED_SERIALIZER_AFTER_BASE_WITH_VERSION(BaseDocument, 1, 0x00010001, pseudoDoc);
	};

	struct PTArgs : public LDAArgs
	{
		size_t p = 100;
		Float lambda = 0.01;
	};

	class IPTModel : public ILDAModel
	{
	public:
		using DefaultDocType = DocumentPT<TermWeight::one>;
		static IPTModel* create(TermWeight _weight, const PTArgs& args,
			bool scalarRng = false);

		virtual size_t getP() const = 0;
	};
}
