#
# Copyright (C) 2018-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libpipeline
PKG_VERSION:=1.5.3
PKG_RELEASE:=1

PKG_SOURCE_URL:=@SAVANNAH/$(PKG_NAME)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=5dbf08faf50fad853754293e57fd4e6c69bb8e486f176596d682c67e02a0adb0

PKG_LICENSE:=GPL-3.0-only
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libpipeline
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=pipeline manipulation library
	URL:=http://libpipeline.nongnu.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libpipeline/description
 libpipeline is a C library for setting up and running pipelines of processes.
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/pipeline.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libpipeline.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libpipeline.pc $(1)/opt/lib/pkgconfig
endef

define Package/libpipeline/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libpipeline.so.* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libpipeline))
