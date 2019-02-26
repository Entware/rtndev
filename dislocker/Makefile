#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=dislocker
PKG_VERSION:=0.7.1
PKG_REV:=3939a18352ee6b44dc6010582645866692b833a3
PKG_RELEASE:=2

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
	DEPENDS:=+libfuse +libmbedtls
	TITLE:=Read BitLocker encrypted volumes under Linux
	URL:=https://github.com/Aorimn/dislocker
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/dislocker/description
 This software has been designed to read BitLocker encrypted partitions under a Linux system.
endef

define Package/dislocker/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/lib
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/opt/bin/dislocker-{bek,file,fuse,metadata} \
		$(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/dislocker $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/* $(1)/opt/lib
endef

$(eval $(call BuildPackage,dislocker))
