##
# Copyright (C) 2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tiv
PKG_SOURCE_DATE:=2019-04-01
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/stefanhaustein/TerminalImageViewer.git
PKG_SOURCE_VERSION:=53dff6f5b933d0aa883868efb9e47d48c2ca6c4f
PKG_MIRROR_HASH:=25c2729b8a683b1d982e5d939ca6743d448d43edbeba66f4d25ef534e9a2c907

PKG_MAINTAINER:=Thomas Kupper <thomas.kupper@gmail.com>
PKG_LICENSE:=GPLv2

PKG_INSTALL=0

include $(INCLUDE_DIR)/package.mk

define Package/tiv
  SECTION:=devel
  CATEGORY:=Utilities
  TITLE:=Program to display images in a terminal
  URL:=https://github.com/stefanhaustein/TerminalImageViewer
  DEPENDS:=libstdcpp
endef

define Package/tiv/description
  Small C++ program to display images in a (modern) terminal using RGB ANSI codes
  and unicode block graphics characters
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) $(PKG_BUILD_DIR)/src/main/cpp/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) $(PKG_JOBS) \
		CXX=$(TARGET_CXX) CPPFLAGS="$(TARGET_CPPFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)" -C $(PKG_BUILD_DIR) all
endef

define Package/tiv/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/tiv $(1)/opt/bin/
endef

$(eval $(call BuildPackage,tiv))
