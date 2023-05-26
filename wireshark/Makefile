#
# Copyright (C) 2020-2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=wireshark
PKG_VERSION:=3.6.14
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://1.eu.dl.wireshark.org/src \
	http://ftp.uni-kl.de/pub/wireshark/src \
	https://wireshark.org/download/src/all-versions
PKG_HASH:=0a8f7bc23056b3e93dc33b9f12241fc487f73259e7299bd20109e84c4bdfc687

# FIXME FAILED: ... run/lemon: Exec format error
PKG_USE_NINJA:=0
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/wireshark
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+bcg729 +glib2 +krb5-libs +libcap +libcares +libgcrypt +libgnutls \
		+liblz4 +libnghttp2 +libopus +libpcap +libspandsp +libspeexdsp \
		+libssh +libxml2 +sbc +zstd
	TITLE:=network protocol analyzer
	URL:=https://www.wireshark.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/wireshark/description
 Wireshark is the world’s foremost and widely-used network protocol analyzer.
endef

CMAKE_OPTIONS += \
	-DBUILD_mmdbresolve=OFF \
	-DBUILD_wireshark=OFF \
	-DENABLE_LUA=OFF

define Build/Compile
	touch $(PKG_BUILD_DIR)/tools/lemon/CMakeFiles/lemon.dir/lemon.c.o
	$(HOSTCC) $(PKG_BUILD_DIR)/tools/lemon/lemon.c \
		-o $(PKG_BUILD_DIR)/run/lemon
	$(call Build/Compile/Default)
endef

define Package/wireshark/install
	$(INSTALL_DIR) $(1)/opt/lib/wireshark
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/wireshark/{extcap,plugins} \
		$(1)/opt/lib/wireshark
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/wireshark $(1)/opt/share
endef

$(eval $(call BuildPackage,wireshark))
