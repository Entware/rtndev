#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Can't update to 15.09 while some errors in sources aren't fixed

include $(TOPDIR)/rules.mk

PKG_NAME:=p7zip
PKG_VERSION:=9.38.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION)_src_all.tar.bz2
PKG_SOURCE_URL:=@SF/p7zip/p7zip/$(PKG_VERSION)
PKG_MD5SUM:=6cba8402ccab2370d3b70c5e28b3d651

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)_$(PKG_VERSION)
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/p7zip
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=compression
	DEPENDS:=+libpthread +libstdcpp
	TITLE:=Command line version of 7-zip for POSIX systems
	URL:=http://p7zip.sourceforge.net
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/p7zip/description
 Command line version of 7-zip for POSIX systems.
endef

MAKE_FLAGS += \
	7za 7zr\
	CXX="$(TARGET_CXX) -O2 -pipe -s -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -DNDEBUG -D_REENTRANT -DENV_UNIX -D_7ZIP_LARGE_PAGES -DBREAK_HANDLER -DUNICODE -D_UNICODE -fPIC" \
	CC="$(TARGET_CC) -O2 -pipe -s -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -DNDEBUG -D_REENTRANT -DENV_UNIX -D_7ZIP_LARGE_PAGES -DBREAK_HANDLER -DUNICODE -D_UNICODE -fPIC" \
	CPPFLAGS="-c -I. -I../../../../C -I../../../myWindows -I../../../include_windows -I../../.. " \
	CXXFLAGS="-c -I. -I../../../../C -I../../../myWindows -I../../../include_windows -I../../.. " \
	LIBS="-lpthread -ldl" \
	DEST_HOME="$(PKG_INSTALL_DIR)/opt"

define Package/p7zip/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/7z{r,a} $(1)/opt/bin/
endef

$(eval $(call BuildPackage,p7zip))
