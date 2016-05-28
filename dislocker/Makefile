#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=dislocker
PKG_VERSION:=0.6.1
PKG_REV:=db4576aac41142362c3c58b07b7fd6c56034dfc4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/Aorimn/dislocker.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/dislocker
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse +libpolarssl
	TITLE:=Read BitLocker encrypted volumes under Linux
	URL:=https://github.com/Aorimn/dislocker
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/dislocker/description
 This software has been designed to read BitLocker encrypted partitions under a Linux system.
endef

define Package/dislocker/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/dislocker-{bek,file,fuse,metadata} $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/dislocker $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/* $(1)/opt/lib
endef

$(eval $(call BuildPackage,dislocker))
