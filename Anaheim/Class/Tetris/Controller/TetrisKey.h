#pragma once

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			ref class TetrisModel;
		}

		namespace Controller
		{
			using namespace System;
			using namespace System::Windows::Forms;
			using namespace Model;

			/**
			 * �e�g���X�L�[�i���J�p�j
			 */
			public ref class PublicTetrisKey abstract
			{
			/**
			 * �R���X�g���N�^
			 */
			public:
				PublicTetrisKey();

			/**
			 * ���\�b�h
			 */
			public:
				/// �o�^�ς݃L�[������
				virtual bool IsRegisteredKey(Keys key) abstract;
				/// ���s
				virtual bool Execute(Keys key) abstract;

			/**
			 * �v���p�e�B
			 */
			public:
				/// ���ړ��L�[�ݒ�
				property array<Keys>^ MoveDownKeys
				{
					virtual void set(array<Keys>^ value) abstract;
				}
				/// ���ړ��L�[�ݒ�
				property array<Keys>^ MoveLeftKeys
				{
					virtual void set(array<Keys>^ value) abstract;
				}
				/// �E�ړ��L�[�ݒ�
				property array<Keys>^ MoveRightKeys
				{
					virtual void set(array<Keys>^ value) abstract;
				}
				/// ����]�L�[�ݒ�
				property array<Keys>^ RotateLeftKeys
				{
					virtual void set(array<Keys>^ value) abstract;
				}
				/// �E��]�L�[�ݒ�
				property array<Keys>^ RotateRightKeys
				{
					virtual void set(array<Keys>^ value) abstract;
				}
				/// �n�[�h�h���b�v�L�[�ݒ�
				property array<Keys>^ HardDropKeys
				{
					virtual void set(array<Keys>^ value) abstract;
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * �e�g���X�L�[
			 */
			ref class TetrisKey : public PublicTetrisKey
			{
			/**
			 * enum class
			 */
			private:
				enum class ActionType
				{
					MoveDown,
					MoveLeft,
					MoveRight,
					RotateLeft,
					RotateRight,
					HardDrop,
					Max
				};

			/**
			 * �t�B�[���h
			 */
			private:
				array<array<Keys>^>^ keysArray;
				TetrisModel^ model;
				Timer^ timer;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisKey(TetrisModel^ model, Timer^ timer);

			/**
			 * ���\�b�h
			 */
			private:
				bool ExecuteCore(ActionType type);

			public:
				/// �o�^�ς݃L�[������
				virtual bool IsRegisteredKey(Keys key) override;
				/// ���s
				virtual bool Execute(Keys key) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// ���ړ��L�[�ݒ�
				property array<Keys>^ MoveDownKeys
				{
					virtual void set(array<Keys>^ value) override { this->keysArray[static_cast<int>(ActionType::MoveDown)] = value; }
				}
				/// ���ړ��L�[�ݒ�
				property array<Keys>^ MoveLeftKeys
				{
					virtual void set(array<Keys>^ value) override { this->keysArray[static_cast<int>(ActionType::MoveLeft)] = value; }
				}
				/// �E�ړ��L�[�ݒ�
				property array<Keys>^ MoveRightKeys
				{
					virtual void set(array<Keys>^ value) override { this->keysArray[static_cast<int>(ActionType::MoveRight)] = value; }
				}
				/// ����]�L�[�ݒ�
				property array<Keys>^ RotateLeftKeys
				{
					virtual void set(array<Keys>^ value) override { this->keysArray[static_cast<int>(ActionType::RotateLeft)] = value; }
				}
				/// �E��]�L�[�ݒ�
				property array<Keys>^ RotateRightKeys
				{
					virtual void set(array<Keys>^ value) override { this->keysArray[static_cast<int>(ActionType::RotateRight)] = value; }
				}
				/// �n�[�h�h���b�v�L�[�ݒ�
				property array<Keys>^ HardDropKeys
				{
					virtual void set(array<Keys>^ value) override { this->keysArray[static_cast<int>(ActionType::HardDrop)] = value; }
				}
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}
