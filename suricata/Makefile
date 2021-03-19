#
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# The newer versions (5.0+)  requires Rust

include $(TOPDIR)/rules.mk

PKG_NAME:=suricata
PKG_VERSION:=4.1.8
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.openinfosecfoundation.org/download
PKG_HASH:=c8a83a05f57cedc0ef81d833ddcfdbbfdcdb6f459a91b1b15dc2d5671f1aecbb

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/suricata
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libyaml +jansson +libpcap +libpcre +file +liblz4 +libcap-ng
	TITLE:=IDS, IPS, NSM engine
	URL:=https://suricata-ids.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/suricata/description
 The Suricata engine is capable of real time intrusion detection (IDS), inline
 intrusion prevention (IPS), network security monitoring (NSM) and offline pcap
 processing. Suricata inspects the network traffic using a powerful and
 extensive rules and signature language, and has powerful Lua scripting support
 for detection of complex threats.
endef

CONFIGURE_ARGS += \
	--disable-static \
	--disable-afl \
	--disable-suricata-update

define Package/suricata/conffiles
/opt/etc/suricata/suricata.yaml
/opt/etc/suricata/classification.config
/opt/etc/suricata/reference.config
/opt/etc/suricata/threshold.config
endef

define Package/suricata/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/suricata $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libhtp*.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/etc/suricata/rules
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/{classification,reference,threshold}.config \
		$(PKG_BUILD_DIR)/suricata.yaml \
		$(1)/opt/etc/suricata
	$(INSTALL_DIR) $(1)/opt/var/log/suricata/{certs,files}
endef

define Package/suricata/postinst
#!/bin/sh

echo 'Current Suricata ruleset can be found at'
echo 'https://rules.emergingthreats.net/open/suricata-4.0/emerging.rules.tar.gz'
endef

$(eval $(call BuildPackage,suricata))
