#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=dropbox-uploader
PKG_VERSION:=1.0-2018.01.22
PKG_RELEASE:=1

PKG_REV:=f1d8544c8f65c44a015cf3e993567bf42187cfac
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/andreafabrizi/Dropbox-Uploader
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/dropbox-uploader
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+bash +curl +sed +coreutils-basename +coreutils-date \
	    +coreutils-stat +coreutils-dd +coreutils-mkdir
	TITLE:=BASH script for Dropbox
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/dropbox-uploader/description
 Dropbox Uploader is a BASH script which can be used to upload, download, 
 delete or list files from Dropbox, an online file sharing, synchronization and backup service.
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/dropbox-uploader/install
	$(INSTALL_DIR) $(1)/opt/{bin,etc,tmp}
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dropbox_uploader.sh $(1)/opt/bin/dropbox_uploader
endef

$(eval $(call BuildPackage,dropbox-uploader))
