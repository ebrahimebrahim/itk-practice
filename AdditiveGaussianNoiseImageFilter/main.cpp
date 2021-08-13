#include "itkAdditiveGaussianNoiseImageFilter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include <iostream>

int main(int argc, char** argv){

    if (argc < 3) {
        std::cerr << "Usage:\n" << argv[0] << " <InputFileName> <OutputFileName>\n";
        return EXIT_FAILURE;
    }
    std::string input_filename = argv[1];
    std::string output_filename = argv[2];

    using PixelType = unsigned char;
    constexpr unsigned int Dimension = 2;
    using ImageType = itk::Image<PixelType, Dimension>;
    using ReaderType = itk::ImageFileReader<ImageType>;
    
    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(input_filename);


    // delete this when you attach the filter:
    // reader->Update();
    // ImageType::Pointer image = reader->GetOutput();
    
    // PixelType & p = image->GetPixel({11,51});
    // std::cout << int(p) << std::endl;

    using FilterType = itk::AdditiveGaussianNoiseImageFilter<ImageType, ImageType>;
    FilterType::Pointer filter = FilterType::New();
    filter->SetInput(reader->GetOutput());
    filter->SetMean(50.);
    filter->SetStandardDeviation(20.);

    using WriterType = itk::ImageFileWriter<ImageType>;
    WriterType::Pointer writer = WriterType::New();
    writer->SetFileName(output_filename);
    writer->SetInput(filter->GetOutput());

    try {
        writer->Update();
    }
    catch (itk::ExceptionObject & error) {
        std::cerr << "Error: " << error << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
