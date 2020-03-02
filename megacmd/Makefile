#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=megacmd
PKG_VERSION:=1.1.0
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_REV:=4b47132bde518b5469a819bb5ae82caea035a4ec
PKG_SOURCE_URL:=https://github.com/meganz/MEGAcmd
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/megacmd
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libcares +libcryptoxx +libcurl +libfuse +libreadline \
	   +libncursesw +libsodium +libsqlite3 +libuv +libatomic +libpcre
	TITLE:=Command Line Interactive and Scriptable Application
	URL:=https://github.com/meganz/megacmd
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/megacmd/description
 MEGAcmd provides non UI access to MEGA services. It intends to offer all the
 functionality with your MEGA account via commands.
endef

MSDK=meganz-sdk-3.6.6.tar.bz2

TARGET_CXXFLAGS += -pthread

TARGET_LDFLAGS += -latomic

CONFIGURE_ARGS += \
	--disable-doxygen-doc \
	--without-freeimage \
	--with-libuv=$(STAGING_DIR)/opt \
	--with-ffmpeg=$(STAGING_DIR)/opt

define Build/Prepare
	$(PKG_UNPACK)
	rm -fr $(PKG_BUILD_DIR)/sdk/*
	tar -xvjf $(DL_DIR)/$(MSDK) --strip-components=1 -C $(PKG_BUILD_DIR)/sdk
	$(Build/Patch)
endef

define Package/megacmd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
	$(SED) 's,^#!.*bash,#!/opt/bin/sh,' $(1)/opt/bin/*

	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmega.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,megacmd))
